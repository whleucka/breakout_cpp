#include "game.hpp"
#include "brick.hpp"

#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <print>
#include <string>

Game::Game() {
  window = new Window{30.0f, 800, 600, std::string("Breakout")};
  init();
}

Game::~Game() {
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  delete window;
}

void Game::init() {
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

void Game::checkInit(bool test, std::string description) {
  if (!test) {
    std::println("Failed to initialze {}", description);
    std::exit(1);
  }
}

void Game::setup() { score = 0; }

std::string Game::formatScore() {
  return std::format("Score: {}", std::to_string(score));
}

void Game::move() {
  // Move stuff 🚀
}

void Game::draw() {
  Brick brick = Brick(50.0f,50.0f,35.0f,10.0f,255.0f,255.0f,255.0f,1.0f);
  al_clear_to_color(al_map_rgb(0, 0, 0));
  al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, formatScore().c_str());

  // Drawing stuff 🎨
  brick.draw();

  al_flip_display();
}

int Game::run() {
  setup();

  bool done = false;
  bool redraw = true;
  ALLEGRO_EVENT event;

  al_start_timer(timer);


  for (;;) {
    al_wait_for_event(queue, &event);

    switch (event.type) {
    case ALLEGRO_EVENT_TIMER:
      move();
      redraw = true;
      break;

    case ALLEGRO_EVENT_KEY_DOWN:
      if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        done = true;
      }
      break;
    case ALLEGRO_EVENT_DISPLAY_CLOSE:
      done = true;
      break;
    }

    if (done)
      break;

    if (redraw && al_is_event_queue_empty(queue)) {
      draw();

      redraw = false;
    }
  }
  return 1;
}
