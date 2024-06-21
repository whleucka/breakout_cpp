#pragma once

namespace Quad {
  struct Pos {
    float x, y;
  };

  struct Dim {
    float w, h;
  };

  struct Colour {
    float r, g, b, a;
  };

  class Quad
  {
  public:
    Quad(float posX, float posY, float width, float height, float red,
          float green, float blue, float alpha);
    virtual ~Quad();
    virtual void draw();
    Pos *pos;
    Dim *dim;
    Colour *colour;
  };
}
