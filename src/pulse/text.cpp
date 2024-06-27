#include "pulse/text.hpp"
#include <allegro5/allegro_font.h>

namespace Pulse {

Text::Text(ALLEGRO_FONT *font, char *text, float x, float y, float r,
           float g, float b, float a)
    : text(text), font(font), pos(new Pos{x, y}),
      colour(new Colour{r, g, b, a}) {}

Text::~Text() {}

void Text::draw() const {
  al_draw_text(font, al_map_rgba(colour->r, colour->g, colour->b, colour->a),
               pos->x, pos->y, 0, text);
}

} // namespace Pulse
