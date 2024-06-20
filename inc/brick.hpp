#pragma once

struct Pos {
  float x, y;
};

struct Size {
  float w, h;
};

struct Colour {
  float r, g, b, a;
};

class Brick {
public:
  Brick(float posX, float posY, float width, float height, float red,
        float green, float blue, float alpha);
  ~Brick();
  void draw();

private:
  Pos *pos;
  Size *size;
  Colour *colour;
};
