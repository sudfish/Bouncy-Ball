#include "Game.hpp"
#include "Ball.hpp"
#include "global.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <string>

namespace bouncyball {
    Game::Game(int width, int height, std::string title){
        srand(time(NULL));
        this->font.loadFromFile(WIN_FONT);
        this->damping_text.setFont(this->font);
        this->gravity_text.setFont(this->font);
        this->damping_text.setCharacterSize(WIN_FONT_SIZE);
        this->gravity_text.setCharacterSize(WIN_FONT_SIZE);
        this->damping_text.setString("(D)amping");
        this->gravity_text.setString("(G)ravity");
        this->damping_text.setPosition(WIN_WIDTH - this->damping_text.getGlobalBounds().width, 0);
        this->window.create(
                sf::VideoMode(width, height),
                title, 
                sf::Style::Close | sf::Style::Titlebar
            );
        ball = new Ball(BALL_RADIUS, BALL_COLOR);
    } 

    void Game::Run(){
        float new_time, frame_time, interpolation;
        float current_time = this->clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(this->window.isOpen()){
            new_time = this->clock.getElapsedTime().asSeconds();
            frame_time = new_time - current_time;
            frame_time = frame_time > 0.25f ? 0.25f : frame_time;

            current_time = new_time;
            if(!this->paused) accumulator += frame_time;

            this->HandleInput();
            while(accumulator >= this->dt && !this->paused){
                this->Update();
                accumulator -= this->dt;
            }
            
            interpolation = accumulator/this->dt;
            this->Draw(interpolation);
        }
    }

    void Game::HandleInput(){
        sf::Event event;

        while (this->window.pollEvent(event)) {
            this->HandleGeneralInput(event);
        }
    }

    void Game::HandleGeneralInput(sf::Event &event){
        switch (event.type) {
            case sf::Event::Closed:
                this->Quit();
                break;

            case sf::Event::KeyPressed:
                switch (event.key.code) {
                    case sf::Keyboard::Q:
                        this->Quit();
                        break;

                    case sf::Keyboard::P:
                        this->paused ? this->Resume() : this->Pause();
                        break;

                    case sf::Keyboard::G:
                        if(!this->paused){
                            this->ball->ToggleGravity();
                        } 
                        break;

                    case sf::Keyboard::D:
                        if(!this->paused) this->ball->ToggleDamping();
                        break;
                    default:
                        break;
                }
                break;

            default:
                break;
        }
    }

    void Game::Update(){
        this->ball->has_gravity ? this->gravity_text.setFillColor(WIN_FONT_COLOR_ON) : this->gravity_text.setFillColor(WIN_FONT_COLOR_OFF);
        this->ball->has_damping ? this->damping_text.setFillColor(WIN_FONT_COLOR_ON) : this->damping_text.setFillColor(WIN_FONT_COLOR_OFF);
        this->ball->Update(this->dt);
    }

    void Game::Draw(float dt){
        this->window.clear();
        this->window.draw(this->damping_text);
        this->window.draw(this->gravity_text);
        this->window.draw(this->ball->ball_shape);
        this->window.display();
    }

    void Game::Pause(){
        this->paused = true;
    }

    void Game::Resume(){
        this->paused = false;
    }
    
    void Game::Quit(){
        this->window.close(); 
    }
}
