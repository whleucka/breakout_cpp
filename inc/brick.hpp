#pragma once

#include "quad.hpp"

class Brick : public Pulse::Quad {
public:
  Brick(float posX, float posY, float width, float height, float red,
        float green, float blue, float alpha);
  ~Brick();
  bool isAlive() { return alive; }
  void kill() { alive = false; }

private:
  bool alive;
};
