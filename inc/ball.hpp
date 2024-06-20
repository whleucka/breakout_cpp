#pragma once

struct Pos {
  float x, y;
};

struct Size {
  float r;
};

struct Colour {
  float r, g, b, a;
};

class Ball {
public:
  Ball(float posX, float posY, float radius, float red, float green, float blue, float alpha);
  ~Ball();
  void draw();

private:
  Pos *pos;
  Size *size;
  Colour *colour;
};
