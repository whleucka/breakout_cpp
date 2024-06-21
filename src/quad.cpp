#include "quad.hpp"
#include <allegro5/allegro_primitives.h>

namespace Quad {
  Quad::Quad(float posX, float posY, float width, float height, float red,
               float green, float blue, float alpha)
      : pos(new Pos{posX, posY}), dim(new Dim{width, height}),
        colour(new Colour{red, green, blue, alpha}) {}

  Quad::~Quad()
  {
    delete pos;
    delete colour;
    delete dim;
  }

  void Quad::draw() {
    al_draw_filled_rectangle(
        pos->x, pos->y, pos->x + dim->w, pos->y + dim->h,
        al_map_rgba_f(colour->r, colour->g, colour->b, colour->a));
  }
}
