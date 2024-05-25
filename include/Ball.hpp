#pragma once

#include "global.hpp"
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>


namespace bouncyball {
    class Ball {
    public:
        Ball(float radius, sf::Color color);
        sf::CircleShape ball_shape;

        bool has_gravity = true;
        bool has_damping = true;

        void Update(float dt);
        void ToggleGravity();
        void ToggleDamping();
    private:
        sf::Vector2f velocity = sf::Vector2f(20.0f, 0.0f);
        sf::Vector2f gravity = sf::Vector2f(0.0f, BALL_GRAVITY_FACTOR);

        float damping = BALL_DAMPING_FACTOR;

        sf::Sound sound;
        sf::SoundBuffer sound_buffer;

        void ApplyGravity(float dt);
        void ApplyDamping(float dt);
        void ChangeColor(sf::Color color);
        void HandleCollisions();
        void HandleSounds();
        void Move(float dt);
    };
}
