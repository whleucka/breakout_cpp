#include "pulse/engine.hpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <math.h>
#include <print>
#include <string>

namespace Pulse {
Engine::Engine() { init(); }

Engine::~Engine() {
  delete window;
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
}

void Engine::init() {
  state = GameState::START;
  window = new Window;

  checkInit(al_init(), "allegro");

  checkInit(al_install_keyboard(), "keyboard");

  timer = al_create_timer(1.0 / window->fps);
  checkInit(timer, "timer");

  queue = al_create_event_queue();
  checkInit(queue, "queue");

  disp = al_create_display(window->width, window->height);
  checkInit(disp, "display");

  font = al_create_builtin_font();
  checkInit(font, "font");

  checkInit(al_init_primitives_addon(), "primitives");

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_timer_event_source(timer));
}

void Engine::checkInit(bool test, std::string description) {
  if (!test) {
    std::println("Failed to initialze {}", description);
    std::exit(1);
  }
}

void Engine::draw() {
  al_clear_to_color(al_map_rgb(0, 0, 0));

  render();

  al_flip_display();
}

void Engine::loop() {
  setupGame();
  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(timer);

  double previous_time = al_get_time();
  double current_time;
  double dt; // delta time

  // The game loop
  for (;;) {
    al_wait_for_event(queue, &event);

    tick();

    switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      current_time = al_get_time();

      // Delta time (how much time passed between buffers)
      dt = current_time - previous_time;
      previous_time = current_time;

      // Move stuff 🚀
      move(dt);

      redraw = true;
      break;

    case ALLEGRO_EVENT_KEY_DOWN:
      keydown(event.keyboard.keycode);
      break;
    case ALLEGRO_EVENT_KEY_UP:
      keyup(event.keyboard.keycode);
      break;
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;
    }

    // Exit game start loop
    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue)) {
      // Drawing stuff 🎨
      draw();

      redraw = false;
    }
  }
}

int Engine::run() {
  switch (state) {
  case GameState::LOADING:
    loading();
    break;
  case GameState::MENU:
    menu();
    break;
  case GameState::START:
    loop();
    break;
  case GameState::PAUSE:
    pause();
    break;
  case GameState::GAME_OVER:
    gameOver();
    break;
  }
  return 0;
}
} // namespace Pulse
