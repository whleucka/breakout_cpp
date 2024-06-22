#pragma once

#include "ball.hpp"
#include "globals.hpp"
#include "ball.hpp"
#include "player.hpp"
#include "brick.hpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <string>
#include <vector>

enum GameState {
  MENU = 0,
  START,
  PAUSE,
  GAME_OVER,
};

class Game {
public:
  Game();
  ~Game();
  int run();

private:
  int state;
  Window *window;
  Player *player;
  Ball *ball;
  std::vector<Brick*> bricks;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_FONT *font;
  std::string formatScore();
  void displayScore();
  int score, level, lives;
  void start();
  void end();
  void init();
  void checkInit(bool test, std::string description);
  void setupGame();
  void loadLevel(int level);
  void move(double dt);
  void draw();
};
