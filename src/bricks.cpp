#include "bricks.hpp"
#include <math.h>

Bricks::Bricks(Window *window): window(window)
{}

Bricks::~Bricks()
{}

void Bricks::loadLevel(int level) {
  // TODO: load levels from files
  float width = 40.0f, height = 15.0f;
  float startPosX = 0.0f, startPosY = 40.0f;
  int level_mod = floor(10 * level * 0.25);

  int columns = floor(window->width / width);
  int rows = std::min(30, level_mod);

  for (auto j = 0; j < rows; ++j) {
    for (auto i = 0; i < columns; ++i) {
      Brick *brick = new Brick(startPosX + width * i, startPosY + height * j,
                               width, height, 0.0f, 0.0f, 255.0f, 0.3f);
      bricks.push_back(brick);
    }
  }
}

void Bricks::draw()
{
  for (auto brick : bricks) {
    if (brick->isAlive())
      brick->draw();
  }
}

bool Bricks::cleared()
{
  int bricksExist = 0;
  for (auto brick : bricks) {
    if (brick->isAlive()) {
      bricksExist++;
    }
  }
  return bricksExist == 0;
}
