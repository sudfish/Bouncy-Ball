#pragma once

#include "global.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
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

            bool paused = false;

            void HandleInput();
            void Update();
            void Draw(float dt);
            void Quit();
    };
}
