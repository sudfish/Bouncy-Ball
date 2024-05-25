#pragma once

#include "Ball.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>
#include <string>

namespace bouncyball {
    class Game{
        public:
            Game(int width, int height, std::string title);
            void Run();
            
        private:
            const float dt = 1.0f/60.0f;
            std::string title;
            sf::RenderWindow window;
            sf::Clock clock;

            sf::Font font;

            sf::Text damping_text;
            sf::Text gravity_text;

            bool paused = false;

            Ball *ball;

            void HandleInput();
            void HandleGeneralInput(sf::Event &event);
            void Update();
            void Draw(float dt);
            void Pause();
            void Resume();
            void Quit();
    };
}
