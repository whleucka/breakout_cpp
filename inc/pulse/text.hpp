#pragma once

#include "structs.hpp"

#include <allegro5/allegro_font.h>

namespace Pulse {

class Text {
public:
  Text() = default;
  Text(ALLEGRO_FONT *font, char *text, float x = 10.0f, float y = 10.0f,
       float r = 255.0f, float g = 255.0f, float b = 255.0f, float a = 1.0f);
  virtual ~Text();
  char *text;
  ALLEGRO_FONT *font;
  Pos *pos;
  Colour *colour;

private:
  virtual void draw() const;
};

} // namespace Pulse
