#pragma once

#include "structs.hpp"

#include <allegro5/allegro_font.h>
#include <string>

namespace Pulse {

class Text {
public:
  Text() = default;
  Text(std::string body, ALLEGRO_FONT *font, float x = 10.0f, float y = 10.0f,
       float r = 255.0f, float g = 255.0f, float b = 255.0f, float a = 1.0f);
  virtual ~Text();
  Pos *pos;
  Colour *colour;
  virtual void draw() const;

private:
  std::string body;
  ALLEGRO_FONT *font;
};

} // namespace Pulse
