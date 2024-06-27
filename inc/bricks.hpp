#pragma once

#include "brick.hpp"
#include <vector>

class Bricks {
public:
  Bricks(Window *window);
  ~Bricks();
  void loadLevel(int level);
  std::vector<Brick* > getBricks() { return bricks; }
  void draw() const;
  bool cleared();

private:
  Window *window;
  std::vector<Brick *> bricks;
};
