#pragma once

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <string>

struct Window {
  float fps;
  int width, height;
  std::string title;
};

class Game {
public:
  Game();
  ~Game();
  int run();

private:
  Window *window;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_FONT *font;
  std::string formatScore();
  int score;
  void init();
  void checkInit(bool test, std::string description);
  void setup();
  void move();
  void draw();
};
