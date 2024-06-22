#include "brick.hpp"

Brick::Brick(float posX, float posY, float width, float height, float red,
             float green, float blue, float alpha)
    : Quad::Quad(posX, posY, width, height, red, green, blue, alpha, false),
      alive(true) {}

Brick::~Brick() {}
