#include "Ball.hpp"
#include "global.hpp"
#include "CollisionHandler.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Mouse.hpp>


namespace bouncyball {
    Ball::Ball(float radius, sf::Color color){
        this->sound_buffer.loadFromFile(BALL_SOUND_PATH);
        this->sound.setBuffer(this->sound_buffer);
        this->ball_shape.setFillColor(color);
        this->ball_shape.setRadius(radius);
        this->ball_shape.setOrigin(
                int(this->ball_shape.getGlobalBounds().width/2), 
                int(this->ball_shape.getGlobalBounds().height/2)
                );
        this->ball_shape.setPosition(sf::Vector2f(int(WIN_WIDTH/2), int(WIN_HEIGHT/2)));
    }

    void Ball::Update(float dt, sf::RenderWindow &window){
        if(this->is_tracking) this->TrackMouse(window);
        this->HandleCollisions();
        this->HandleSounds();
        this->Move(dt);
    }

    void Ball::ApplyGravity(float dt){
        this->velocity.y -= this->gravity.y * dt;
    }

    void Ball::ApplyDamping(float dt){
        this->velocity *= (1.0f - this->damping * dt);
    }

    void Ball::ToggleGravity(){
        this->has_gravity = !this->has_gravity;
    }

    void Ball::ToggleDamping(){
        this->has_damping = !this->has_damping;
    }

    void Ball::ChangeColor(sf::Color color){
        this->ball_shape.setFillColor(color);
    }

    void Ball::ClearVelocity(){
        this->velocity = sf::Vector2f(0.0f, 0.0f);
    }

    void Ball::TrackMouse(sf::RenderWindow &window){
        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
        this->ball_shape.setPosition(mouse_pos.x, mouse_pos.y);
    }

    void Ball::Move(float dt){
        if(this->has_gravity) this->ApplyGravity(dt);
        if(this->has_damping) this->ApplyDamping(dt);
        this->ball_shape.move(this->velocity);
    }

    void Ball::DragVelocity(sf::Vector2i prev_pos, sf::Vector2i curr_pos){
        this->velocity.x = (curr_pos.x - prev_pos.x) * 0.2f;
        this->velocity.y = (curr_pos.y - prev_pos.y) * 0.2f;
    }

    void Ball::HandleCollisions(){
        if(CollisionHandler::NorthWallCollision(this->ball_shape)){
            this->velocity.y *= -1;
            this->ball_shape.setPosition(
                    this->ball_shape.getPosition().x,
                    this->ball_shape.getRadius()
                    );
        }
        if(CollisionHandler::SouthWallCollision(this->ball_shape)){
            this->velocity.y *= -1;
            this->ball_shape.setPosition(
                    this->ball_shape.getPosition().x,
                    WIN_HEIGHT - this->ball_shape.getRadius()
                    );
        }
        if(CollisionHandler::EastWallCollision(this->ball_shape)){
            this->velocity.x *= -1;
            this->ball_shape.setPosition(
                    WIN_WIDTH - this->ball_shape.getRadius(),
                    this->ball_shape.getPosition().y
                    );
        }
        if(CollisionHandler::WestWallCollision(this->ball_shape)){
            this->velocity.x *= -1;
            this->ball_shape.setPosition(
                    this->ball_shape.getRadius(),
                    this->ball_shape.getPosition().y
                    );
        }
    }

    void Ball::HandleSounds(){
        if(
                CollisionHandler::SouthWallCollision(this->ball_shape) &&
                this->velocity.y < BALL_SOUND_VELOCITY_LIMIT
          ){
            this->sound.play();
        }
        if(
                CollisionHandler::NorthWallCollision(this->ball_shape) &&
                this->velocity.y > BALL_SOUND_VELOCITY_LIMIT
          ){
            this->sound.play();
        }
        if(
                CollisionHandler::EastWallCollision(this->ball_shape) &&
                this->velocity.x < BALL_SOUND_VELOCITY_LIMIT
          ){
            this->sound.play();
        }
        if(
                CollisionHandler::WestWallCollision(this->ball_shape) &&
                this->velocity.x > BALL_SOUND_VELOCITY_LIMIT
          ){
            this->sound.play();
        }
    }
}
