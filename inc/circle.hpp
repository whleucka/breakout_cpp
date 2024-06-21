#pragma once

namespace Circle {
  struct Pos {
    float x, y;
  };

  struct Dim {
    float r;
  };

  struct Colour {
    float r, g, b, a;
  };

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
