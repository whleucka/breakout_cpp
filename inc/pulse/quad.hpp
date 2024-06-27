#pragma once

#include "structs.hpp"

namespace Pulse {

class Quad {
public:
  Quad() = default;
  Quad(float posX = 0.0f, float posY = 0.0f, float width = 10.0f,
       float height = 10.0f, float red = 255.0f, float green = 255.0f,
       float blue = 255.0f, float alpha = 255.0f, bool solid = true);
  virtual ~Quad();
  virtual void draw() const;
  Pos *pos;
  Dim *dim;
  Colour *colour;
  bool solid;
};

} // namespace Pulse
