#pragma once

#include "structs.hpp"

namespace Pulse {
class Quad {
public:
  Quad(float posX, float posY, float width, float height, float red,
       float green, float blue, float alpha, bool solid);
  virtual ~Quad();
  virtual void draw();
  Pos *pos;
  Dim *dim;
  Colour *colour;
  bool solid;
};
} // namespace Quad
