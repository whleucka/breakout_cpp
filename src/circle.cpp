#include "circle.hpp"
#include <allegro5/allegro_primitives.h>

namespace Pulse {
  Circle::Circle(float posX, float posY, float radius, float red, float green,
                 float blue, float alpha)
      : pos(new Pos{posX, posY}), dim(new Dim{0.0f, 0.0f, radius}),
        colour(new Colour{red, green, blue, alpha}) {}

  Circle::~Circle() {
    delete pos;
    delete colour;
    delete dim;
  }

    void Circle::draw() {
      al_draw_filled_circle(
          pos->x, pos->y, dim->r,
          al_map_rgba_f(colour->r, colour->g, colour->b, colour->a));
    }
  }

