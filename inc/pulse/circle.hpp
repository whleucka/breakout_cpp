#pragma once

#include "structs.hpp"

namespace Pulse {
  class Circle {
  public:
    Circle(float posX, float posY, float radius, float red, float green,
           float blue, float alpha);
    virtual ~Circle();
    virtual void draw();
    Pos *pos;
    Dim *dim;
    Colour *colour;
  };
}
