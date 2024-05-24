#include "Game.hpp"
#include "Ball.hpp"
#include "global.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <string>

namespace bouncyball {
    Game::Game(int width, int height, std::string title){
        srand(time(NULL));
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
            accumulator += frame_time;

            while(accumulator >= this->dt){
                this->HandleInput();
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
            switch (event.type) {
                case sf::Event::Closed:
                    this->Quit();
                    break;

                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Q:
                            this->Quit();
                            break;
                        default:
                            break;
                    }
                    break;

                default:
                    break;
            }
        }
    }

    void Game::Update(){
        this->ball->Update(this->dt);
    }

    void Game::Draw(float dt){
        this->window.clear();
        this->window.draw(this->ball->ball_shape);
        this->window.display();
    }
    
    void Game::Quit(){
        this->window.close(); 
    }
}
