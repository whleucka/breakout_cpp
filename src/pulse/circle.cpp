#include "pulse/circle.hpp"
#include <allegro5/allegro_primitives.h>

namespace Pulse {

Circle::Circle(float posX, float posY, float radius, float red, float green,
               float blue, float alpha, bool solid)
    : pos(new Pos{posX, posY}), dim(new Dim{0.0f, 0.0f, radius}),
      colour(new Colour{red, green, blue, alpha}), solid(solid) {}

Circle::~Circle() {
  delete pos;
  delete colour;
  delete dim;
}

void Circle::draw() const {
  if (solid) {
    al_draw_filled_circle(
        pos->x, pos->y, dim->r,
        al_map_rgba(colour->r, colour->g, colour->b, colour->a));
  } else {
    al_draw_circle(pos->x, pos->y, dim->r,
                   al_map_rgba(colour->r, colour->g, colour->b, colour->a),
                   2.0f);
  }
}

} // namespace Pulse
