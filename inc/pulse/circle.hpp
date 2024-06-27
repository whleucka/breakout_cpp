#pragma once

#include "structs.hpp"

namespace Pulse {

class Circle {
public:
  Circle() = default;
  Circle(float posX = 0.0f, float posY = 0.0, float radius = 5.0f,
         float red = 255.0f, float green = 255.0f, float blue = 255.0f,
         float alpha = 1.0f, bool solid = true);
  virtual ~Circle();
  virtual void draw() const;
  Pos *pos;
  Dim *dim;
  Colour *colour;
private:
  bool solid;
};

} // namespace Pulse
