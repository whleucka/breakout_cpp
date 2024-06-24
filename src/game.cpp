#include "game.hpp"
#include "math.h"
#include <allegro5/allegro_font.h>
#include <format>
#include <print>

Game::~Game() {
  delete player;
  delete ball;
}

int Game::entryPoint() {
  score = 0;
  level = 1;
  lives = 2;
  loadLevel(level);
  setupGame();
  return Engine::run();
}

void Game::loadLevel(int level) {
  float width = 40.0f, height = 15.0f;
  float startPosX = 0.0f, startPosY = 40.0f;
  int level_mod = floor(10 * level * 0.25);

  int columns = floor(window->width / width);
  int rows = std::min(30, level_mod);

  for (auto j = 0; j < rows; ++j) {
    for (auto i = 0; i < columns; ++i) {
      Brick *brick = new Brick(startPosX + width * i, startPosY + height * j,
                               width, height, 0.0f, 0.0f, 255.0f, 0.3f);
      bricks.push_back(brick);
    }
  }
}

void Game::displayScore() {
  al_draw_text(font, al_map_rgb(255, 255, 255), 10, 10, 0,
               formatScore().c_str());
}

void Game::setupGame() {
  Engine::setupGame();
  player = new Player((window->width / 2.0f) - 50.0f, window->height - 25,
                      100.0f, 10.0f, 255.0f, 0.0f, 0.0f, 1.0f, window);
  ball =
      new Ball((window->width / 2.0f) - 50.0f, window->height - 40.0f, 5.0f,
               255.0f, 255.0f, 255.0f, 1.0f, window, player, &bricks, &score);
}

std::string Game::formatScore() {
  return std::format("Level: {} : Lives: {}, Score: {}", std::to_string(level),
                     std::to_string(lives), std::to_string(score));
}

/**
 * @param double dt delta time
 */
void Game::move(double dt) {
  ball->move(dt);
  player->move(dt);
}

void Game::render() {
  displayScore();

  for (auto brick : bricks) {
    if (brick->isAlive())
      brick->draw();
  }

  ball->draw();
  player->draw();
}

void Game::tick() {
  Engine::tick();
  // Oof
  if (!ball->isAlive()) {
    if (lives-- <= 0) {
      std::println("Game over! Score: {}", std::to_string(score));
      // FIXME: we need to exit here
    }
    ball->reset();
  }

  int bricksExist = 0;
  for (auto brick : bricks) {
    if (brick->isAlive()) {
      bricksExist++;
    }
  }
  if (!bricksExist) {
    level++;
    lives++;
    // FIXME: this should go to next level and restart gameplay
  }
}

void Game::keydown(int type) {
  switch (type) {
  case ALLEGRO_KEY_H:
  case ALLEGRO_KEY_A:
  case ALLEGRO_KEY_LEFT:
    player->keyboard(-1);
    break;
  case ALLEGRO_KEY_L:
  case ALLEGRO_KEY_D:
  case ALLEGRO_KEY_RIGHT:
    player->keyboard(1);
    break;
  }
}

void Game::keyup(int /*type*/) { player->keyboard(0); }
