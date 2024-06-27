#include "game.hpp"
#include "math.h"
#include "pulse/text.hpp"
#include <format>
#include <print>
#include <string>

Game::~Game() {
  delete player;
  delete ball;
  delete bricks;
}

int Game::entryPoint() {
  score = 0;
  level = 1;
  lives = 2;
  return Engine::run();
}

void Game::displayScoreboard() const {
  std::string body =
      std::format("Level: {} : Lives: {}, Score: {}", std::to_string(level),
                  std::to_string(lives), std::to_string(score));
  Pulse::Text scoreboard = Pulse::Text(body.c_str(), font);
  scoreboard.draw();
}

void Game::setupGame() {
  Engine::setupGame();
  window->title = "Breakout CPP";

  bricks = new Bricks(window);
  bricks->loadLevel(level);

  player = new Player((window->width / 2.0f) - 50.0f, window->height - 25,
                      100.0f, 10.0f, 255.0f, 0.0f, 0.0f, 1.0f, true, window);
  ball = new Ball((window->width / 2.0f) - 50.0f, window->height - 40.0f, 5.0f,
                  255.0f, 255.0f, 255.0f, 1.0f, true, window, player, bricks,
                  &score);
}

/**
 * @param double dt delta time
 */
void Game::move(double dt) {
  ball->move(dt);
  player->move(dt);
}

void Game::render() const {
  displayScoreboard();
  bricks->draw();
  ball->draw();
  player->draw();
}

void Game::tick() {
  Engine::tick();

  // Oof
  if (!ball->isAlive()) {
    if (lives-- <= 0) {
      gameOver();
    }
    ball->reset();
  }

  // Next level?
  if (bricks->cleared()) {
    nextLevel();
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

void Game::gameOver() {
  Engine::gameOver();
  std::println("Game over! Score: {}", std::to_string(score));
}

void Game::nextLevel() {
  level++;
  lives++;
  ball->reset();
  bricks->loadLevel(level);
}
