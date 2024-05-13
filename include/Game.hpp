#pragma once

#include <SFML/Graphics.hpp>

#include <memory>


namespace bouncyball {
    struct GameData {
        sf::RenderWindow window;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
        public:
            Game(int width, int height, std::string title);

        private:
            const float dt = 1.0f/30.0f;
            sf::Clock clock;

            GameDataRef data = std::make_shared<GameData>();

            void Run();
            void HandleInput();
            void Pause();
            void Quit();
    };
}
