#include "ball.hpp"
#include <allegro5/allegro_primitives.h>

Ball::Ball(float posX, float posY, float radius, float red, float green,
           float blue, float alpha)
    : pos(new Pos{posX, posY}), size(new Size{radius}),
      colour(new Colour{red, green, blue, alpha}) {}

Ball::~Ball() {
  delete pos;
  delete size;
}

void Ball::draw() {
  al_draw_filled_circle(pos->x, pos->y, size->r, al_map_rgba_f(colour->r, colour->g, colour->b, colour->a));
}
