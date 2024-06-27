#pragma once

#include "brick.hpp"
#include "bricks.hpp"
#include "player.hpp"
#include "pulse/circle.hpp"
#include "pulse/structs.hpp"

class Ball : public Pulse::Circle {
public:
  Ball(float posX, float posY, float radius, float red, float green, float blue,
       float alpha, Window *window, Player *player,
       Bricks *bricks, unsigned int *score);
  ~Ball();
  void move(double dt);
  void reset();
  bool isAlive() { return alive; }

private:
  const Window *window;
  Player *player;
  Bricks *bricks;
  void detectWalls();
  void detectPlayer();
  void detectBricks();
  bool isBrickCollision(Brick *brick, float posX, float posY) const;
  bool isPlayerCollision(Player *player, float posX, float posY) const;
  float speed;
  int dx, dy;
  unsigned int *score;
  bool alive;
};
