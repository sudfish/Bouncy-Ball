#include "CollisionHandler.hpp"
#include "global.hpp"

namespace bouncyball {
    bool CollisionHandler::WestWallCollision(sf::CircleShape &ball){
        return ball.getPosition().x-ball.getRadius() <= 0 ? true : false; 
    }

    bool CollisionHandler::EastWallCollision(sf::CircleShape &ball){
        return ball.getPosition().x+ball.getRadius() >= WIN_WIDTH ? true : false; 
    }

    bool CollisionHandler::NorthWallCollision(sf::CircleShape &ball){
        return ball.getPosition().y-ball.getRadius() <= 0 ? true : false; 
    }

    bool CollisionHandler::SouthWallCollision(sf::CircleShape &ball){
        return ball.getPosition().y+ball.getRadius() >= WIN_HEIGHT ? true : false; 
    }
}
