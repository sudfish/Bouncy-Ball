#pragma once

#include "global.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


namespace bouncyball {
    class Ball {
    public:
        Ball(float radius, sf::Color color);
        sf::CircleShape ball_shape;

        void Update(float dt);
    private:
        sf::Vector2f velocity = sf::Vector2f(20.0f, 0.0f);
        sf::Vector2f gravity = sf::Vector2f(0.0f, BALL_GRAVITY_FACTOR);
        bool has_gravity = true;
        float damping = BALL_DAMPING_FACTOR;

        void ApplyGravity(float dt);
        void ToggleGravity();
        void HandleCollisions();
        void Move(float dt);
    };
}
