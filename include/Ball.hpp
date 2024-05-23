#pragma once


#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


namespace bouncyball {
    class Ball {
    public:
        Ball(float radius, sf::Color color);
        sf::CircleShape ball_shape;
    private:

    };
}
