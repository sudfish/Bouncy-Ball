#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/System/Vector2.hpp>

namespace bouncyball {
    class CollisionHandler{
        public:
            static bool NorthWallCollision(sf::CircleShape &ball);
            static bool SouthWallCollision(sf::CircleShape &ball);
            static bool EastWallCollision(sf::CircleShape &ball);
            static bool WestWallCollision(sf::CircleShape &ball);
            static bool MouseBallCollision(sf::CircleShape &ball, sf::Vector2i mouse_pos);
    };
}
