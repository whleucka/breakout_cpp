#include "ball.hpp"

Ball::Ball(float posX, float posY, float radius, float red, float green,
           float blue, float alpha, Window *window, Player *player)
    : Circle::Circle(posX, posY, radius, red, green, blue, alpha),
      window(window), player(player) {
  speed = 200.0f;
  dx = 1;
  dy = -1;
}

Ball::~Ball() {}

void Ball::detectWalls() {
  if (pos->x - dim->r < 0) {
    dx = 1;
  }
  if (pos->x + dim->r > window->width) {
    dx = -1;
  }
  if (pos->y - dim->r < 0) {
    dy = 1;
  }
  if (pos->y + dim->r > window->height) {
    dy = -1;
  }
}

void Ball::detectPlayer() {
  // Is the ball in-bounds on the x-axis?
  if (pos->x >= player->pos->x && pos->x <= player->pos->x + player->dim->w) {
    // Is the ball in-bounds on the y-axis?
    if (pos->y >= player->pos->y && pos->y <= player->pos->y + player->dim->h) {
      dy = 1;
    }
  }
}

void Ball::move(double dt) {
  detectWalls();
  detectPlayer();
  pos->x += dx * speed * dt;
  pos->y += dy * speed * dt;
}
