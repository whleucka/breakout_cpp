#pragma once

#include "quad.hpp"

class Brick : public Quad::Quad {
public:
  Brick(float posX, float posY, float width, float height, float red,
        float green, float blue, float alpha);
  ~Brick();
};
