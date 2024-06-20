#include "brick.hpp"
#include <allegro5/allegro_primitives.h>

Brick::Brick(float posX, float posY, float width, float height, float red,
             float green, float blue, float alpha)
    : pos(new Pos{posX, posY}), size(new Size{width, height}),
      colour(new Colour{red, green, blue, alpha}) {}

Brick::~Brick() {
  delete pos;
  delete size;
  delete colour;
}

void Brick::draw() {
  al_draw_filled_rectangle(
      pos->x, pos->y, pos->x + size->w, pos->y + size->h,
      al_map_rgba_f(colour->r, colour->g, colour->b, colour->a));
}
