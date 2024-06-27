#include "ball.hpp"
#include <print>

Ball::Ball(float posX, float posY, float radius, float red, float green,
           float blue, float alpha, bool solid, Window *window, Player *player,
           Bricks *bricks, unsigned int *score)
    : Pulse::Circle(posX, posY, radius, red, green, blue, alpha, solid),
      window(window), player(player), bricks(bricks), score(score),
      alive(true) {
  speed = 300.0f;
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
    alive = false;
    dy = -1;
  }
}

void Ball::detectPlayer() {
  // The ball must be moving south
  if (dy == 1) {
    float posX = dx == 1 ? pos->x + dim->r : pos->x - dim->r;
    float posY = pos->y + dim->r;

    if (isPlayerCollision(player, posX, posY)) {
      dy = -1;
    }
  }
}

bool Ball::isPlayerCollision(Player *player, float posX, float posY) const {
  return (posX >= player->pos->x && posX <= player->pos->x + player->dim->w &&
          posY >= player->pos->y);
}

void Ball::detectBricks() {
  for (auto brick : bricks->getBricks()) {
    if (!brick->isAlive())
      continue;
    float posX = dx == 1 ? pos->x + dim->r : pos->x - dim->r;
    float posY = dy == 1 ? pos->y + dim->r : pos->y - dim->r;

    if (isBrickCollision(brick, posX, posY)) {
      *score += 10;
      dy *= -1;
      brick->kill();
      break;
    }
  }
}

bool Ball::isBrickCollision(Brick *brick, float posX, float posY) const {
  return (posX >= brick->pos->x && posX <= brick->pos->x + brick->dim->w &&
          posY >= brick->pos->y && posY <= brick->pos->y + brick->dim->h);
}

void Ball::move(double dt) {
  if (!isAlive())
    return;
  detectWalls();
  detectBricks();
  detectPlayer();
  pos->x += dx * speed * dt;
  pos->y += dy * speed * dt;
}

void Ball::reset() {
  alive = true;
  pos->x = player->pos->x + (player->dim->w / 2);
  pos->y = player->pos->y;
  dy = -1;
}
