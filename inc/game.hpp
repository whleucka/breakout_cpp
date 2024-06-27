#pragma once

#include "ball.hpp"
#include "bricks.hpp"
#include "player.hpp"
#include "pulse/engine.hpp"

#include <string>

class Game : public Pulse::Engine {
public:
  Game() : Engine(){};
  ~Game();
  int entryPoint();

private:
  unsigned int score, level, lives;
  Player *player;
  Ball *ball;
  Bricks *bricks;

  std::string formatScore() const;
  void nextLevel();
  void displayScoreboard() const;

  void setupGame() override;
  void gameOver() override;

  void move(double dt) override;
  void render() const override;

  void tick() override;
  void keydown(int type) override;
  void keyup(int type) override;
};
