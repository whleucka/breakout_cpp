#include "pulse/quad.hpp"
#include <allegro5/allegro_primitives.h>

namespace Pulse {

Quad::Quad(float posX, float posY, float width, float height, float red,
           float green, float blue, float alpha, bool solid)
    : pos(new Pos{posX, posY}), dim(new Dim{width, height}),
      colour(new Colour{red, green, blue, alpha}), solid(solid) {}

Quad::~Quad() {
  delete pos;
  delete colour;
  delete dim;
}

void Quad::draw() const {
  if (solid) {
    al_draw_filled_rectangle(
        pos->x, pos->y, pos->x + dim->w, pos->y + dim->h,
        al_map_rgba(colour->r, colour->g, colour->b, colour->a));
  } else {
    al_draw_rectangle(pos->x, pos->y, pos->x + dim->w, pos->y + dim->h,
                      al_map_rgba(colour->r, colour->g, colour->b, colour->a),
                      2.0f);
  }
}

} // namespace Pulse
