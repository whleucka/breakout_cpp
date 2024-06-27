#pragma once

#include <pulse/quad.hpp>
#include <pulse/structs.hpp>
#include <allegro5/allegro5.h>

class Player : public Pulse::Quad {
public:
  Player(float posX, float posY, float width, float height, float red,
         float green, float blue, float alpha, bool solid, Window *window);
  ~Player();
  void move(double dt);
  void keyboard(int _dx);

private:
  Window *window;
  float speed;
  int dx;
};
