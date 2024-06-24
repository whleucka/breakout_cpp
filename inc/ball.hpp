#pragma once

#include "brick.hpp"
#include "player.hpp"
#include "pulse/circle.hpp"
#include "pulse/structs.hpp"

#include <vector>

class Ball : public Pulse::Circle {
public:
  Ball(float posX, float posY, float radius, float red, float green, float blue,
       float alpha, Window *window, Player *player,
       std::vector<Brick *> *bricks, unsigned int *score);
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
  unsigned int *score;
  bool alive;
};
