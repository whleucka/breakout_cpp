#include "player.hpp"

Player::Player(float posX, float posY, float width, float height, float red,
               float green, float blue, float alpha, bool solid, Window *window)
    : Quad::Quad(posX, posY, width, height, red, green, blue, alpha, solid),
      window(window) {
  speed = 500.0f;
  dx = 0;
}

Player::~Player() {}

void Player::keyboard(int _dx) { dx = _dx; }

void Player::move(double dt) {
  if (pos->x < 0) {
    pos->x = 0;
    return;
  }
  if (pos->x + dim->w > window->width) {
    pos->x = window->width - dim->w;
    return;
  }
  pos->x += dx * speed * dt;
}
