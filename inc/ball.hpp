#pragma once

#include "brick.hpp"
#include "circle.hpp"
#include "globals.hpp"
#include "player.hpp"

#include <vector>

class Ball : public Pulse::Circle {
public:
  Ball(float posX, float posY, float radius, float red, float green, float blue,
       float alpha, Window *window, Player *player, std::vector<Brick *> *bricks,
       int *score);
  ~Ball();
  void move(double dt);
  void reset();
  bool isAlive() { return alive; }

private:
  const Window *window;
  const Player *player;
  const std::vector<Brick *> *bricks;
  void detectWalls();
  void detectPlayer();
  void detectBricks();
  float speed;
  int dx, dy;
  int *score;
  bool alive;
};
