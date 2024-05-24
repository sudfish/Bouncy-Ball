#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <string>

// Constants
const int WIN_HEIGHT = 500;
const int WIN_WIDTH = 500;

const int BALL_RADIUS = 20;
const sf::Color BALL_COLOR = sf::Color::Red;
const float BALL_GRAVITY_FACTOR = -9.18f;
const float BALL_DAMPING_FACTOR = 0.5f;
const std::string BALL_SOUND_PATH = "../assets/collision.wav";
const float BALL_SOUND_VELOCITY_LIMIT = 0.50f;
