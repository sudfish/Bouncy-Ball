#include "Ball.hpp"
#include "global.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

namespace bouncyball {
    Ball::Ball(float radius, sf::Color color){
        this->ball_shape.setFillColor(color);
        this->ball_shape.setRadius(radius);
        this->ball_shape.setOrigin(sf::Vector2f(int(radius/2), int(radius/2)));
        this->ball_shape.setPosition(sf::Vector2f(int(WIN_WIDTH/2), int(WIN_HEIGHT/2)));
    }

    
}
