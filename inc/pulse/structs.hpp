#pragma once

#include <string>

struct Window {
  float fps = 30.0f;
  int width = 1280, height = 720;
  std::string title = "";
};

struct Colour {
  float r = 255.0f, g = 255.0f, b = 255.0f, a = 1.0f;
};

struct Dim {
  float w = 0.0f, h = 0.0f, r = 0.0f;
};

struct Pos {
  float x = 0.0f, y = 0.0f;
};

