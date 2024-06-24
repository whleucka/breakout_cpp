#pragma once

#include "globals.hpp"
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>

namespace Pulse {
enum GameState {
  LOADING = 0,
  MENU,
  START,
  PAUSE,
  GAME_OVER,
};

class Engine {
public:
  Engine();
  virtual ~Engine();
  int run();

protected:
  Window *window;
  ALLEGRO_TIMER *timer;
  ALLEGRO_EVENT_QUEUE *queue;
  ALLEGRO_DISPLAY *disp;
  ALLEGRO_FONT *font;

  // Init and setup game
  virtual void init();
  virtual void setupGame() {};

  // Events
  virtual void tick() {};
  virtual void keydown(int /*type*/) {};
  virtual void keyup(int /*type*/) {};

  // Move and rendering
  virtual void move(double /*dt*/) {};
  virtual void render() {};

  // Game state methods
  virtual void loading() {};
  virtual void menu() {};
  virtual void pause() {};
  virtual void gameOver() {};

private:
  int state;
  void checkInit(bool test, std::string description);
  void loop();
  void draw();
};
} // namespace Pulse
