#pragma once

#include "ball.hpp"
#include "brick.hpp"
#include "player.hpp"
#include "bricks.hpp"
#include "pulse/engine.hpp"

#include <string>
#include <vector>

class Game : public Pulse::Engine {
public:
  Game(): Engine() {};
  ~Game();
  int entryPoint();

private:
  unsigned int score, level, lives;
  Player *player;
  Ball *ball;
  Bricks *bricks;

  std::string formatScore() const;
  void nextLevel();
  bool checkEndLevel(const std::vector<Brick *> &bricks);
  void displayScore() const;

  void setupGame() override;
  void gameOver() override;

  void move(double dt) override;
  void render() const override;

  void tick() override;
  void keydown(int type) override;
  void keyup(int type) override;
};
