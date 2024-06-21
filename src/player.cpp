#include "player.hpp"
#include <print>

Player::Player(float posX, float posY, float width, float height, float red,
               float green, float blue, float alpha, Window *window)
    : Quad::Quad(posX, posY, width, height, red, green, blue, alpha),
      window(window) {
  speed = 200.0f;
  dx = 0;
}

Player::~Player() {}

void Player::keyboard(int _dx) {
  dx = _dx;
}

void Player::move(double dt) {
  pos->x += dx * speed * dt;
}
