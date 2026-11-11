/// @file main.cpp
/// @brief The Arcade menu

#include <iostream>
#include <string>
#include "arcade.h"
#include "blackjack.h"
#include "dungeon.h"
#include "hangman.h"
#include "input.h"
#include "minesweeper.h"

namespace {
enum class Choice { hangman, dungeon, blackjack, minesweeper, quit, invalid };

void print_menu() {
  std::cout << "\n=== ARCADE ===\n"
            << "1. Hangman\n"
            << "2. Dungeon\n"
            << "3. Blackjack\n"
            << "4. Minesweeper\n"
            << "0. Quit\n";
}

void report_score(const Game &game) {
  std::cout << game.title() << " score: " << game.last_score() << "\n";
}

Choice parse_choice(const std::string &text) {
  if (text == "1") {
    return Choice::hangman;
  }
  if (text == "2") {
    return Choice::dungeon;
  }
  if (text == "3") {
    return Choice::blackjack;
  }
  if (text == "4") {
    return Choice::minesweeper;
  }
  if (text == "0") {
    return Choice::quit;
  }
  return Choice::invalid;
}

} // namespace

int main() {
    Arcade arcade;

    arcade.add(new Hangman());
    arcade.add(new Dungeon());
    arcade.add(new Minesweeper());
    arcade.add(new Blackjack());

    arcade.run();

  return 0;
}
