#pragma once

#include "globals.hpp"
#include "circle.hpp"
#include "player.hpp"

class Ball : public Circle::Circle {
public:
  Ball(float posX, float posY, float radius, float red, float green, float blue,
       float alpha, Window *window, Player *player);
  ~Ball();
  void move(double dt);
private:
  Window *window;
  Player *player;
  void detectWalls();
  void detectPlayer();
  float speed;
  int dx,dy;
};
