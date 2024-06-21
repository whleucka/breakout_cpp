#include "game.hpp"
#include "player.hpp"

#include <algorithm>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <print>
#include <string>
#include <math.h>

Game::Game() { init(); }

Game::~Game() {
  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);
  delete player;
  delete ball;
  delete window;
}

void Game::init() {
  state = GameState::START;

  window = new Window{30.0f, 800, 600, std::string("Breakout")};

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

void Game::loadLevel() {
  float width = 30.0f, height = 10.0f;
  float startPosX = 10.0f, startPosY = 40.0f;
  int level_mod = floor(5 * level / 2);

  int columns = floor(window->width / width);
  int rows = std::min(50, level_mod);

  for (auto j = 0; j < rows; ++j) {
    for (auto i = 0; i < columns; ++i) {
      Brick *brick = new Brick(startPosX + width * i , startPosY + height * j, width, height, 0.0f, 255.0f, 0.0f, 0.5f);
      bricks.push_back(brick);
    }
  }
}

void Game::displayScore() {
  al_draw_text(font, al_map_rgb(255, 255, 255), 0, 0, 0, formatScore().c_str());
}

void Game::setupGame() {
  score = 0;
  level = 1;
  player = new Player((window->width / 2.0f) - 50.0f, window->height - 50,
                      100.0f, 10.0f, 255.0f, 0.0f, 0.0f, 1.0f, window);
  ball = new Ball((window->width / 2.0f) - 50.0f, window->height - 100, 5.0f,
                  255.0f, 255.0f, 255.0f, 1.0f, window, player);
  loadLevel();
}

std::string Game::formatScore() {
  return std::format("Level: {} : Score: {}", std::to_string(level), std::to_string(score));
}

/**
* @param double dt delta time
*/
void Game::move(double dt) {
  ball->move(dt);
  player->move(dt);
}

void Game::draw() {
  al_clear_to_color(al_map_rgb(0, 0, 0));
  displayScore();

  for (auto brick: bricks) {
    brick->draw();
  }

  ball->draw();
  player->draw();

  al_flip_display();
}

void Game::start() {
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
      // Exit application
      if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE) {
        done = true;
      }

      // Change player direction
      if (event.keyboard.keycode == ALLEGRO_KEY_LEFT) {
        player->keyboard(-1);
      } else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT) {
        player->keyboard(1);
      }
      break;
    case ALLEGRO_EVENT_KEY_UP:
      // Player movement stops
      player->keyboard(0);
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

void Game::end() {
}

int Game::run() {
  switch (state) {
    case GameState::MENU:
    break;
    case GameState::START:
      start();
    break;
    case GameState::PAUSE:
    break;
    case GameState::GAME_OVER:
    break;
  }
  return 0;
}
