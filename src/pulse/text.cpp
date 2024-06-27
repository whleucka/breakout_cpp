#include "pulse/text.hpp"
#include <allegro5/allegro_font.h>
#include <string>

namespace Pulse {

Text::Text(std::string body, ALLEGRO_FONT *font, float x, float y, float r,
           float g, float b, float a)
    : pos(new Pos{x, y}), colour(new Colour{r, g, b, a}), body(body),
      font(font) {}

Text::~Text() {}

void Text::draw() const {
  al_draw_text(font, al_map_rgba(colour->r, colour->g, colour->b, colour->a),
               pos->x, pos->y, 0, body.c_str());
}

} // namespace Pulse
