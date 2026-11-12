#include "arcade.h"
#include <iostream>

Arcade::Arcade() : m_count(0) {
    for (int i = 0; i < max_games; ++i) {
        m_games[i] = nullptr;
    }
}


Arcade::~Arcade() {
    for (int i = 0; i < m_count; ++i) {
        delete m_games[i];
    }
}

void Arcade::add(Game *game) {
    if (m_count < max_games) {
        m_games[m_count++] = game;
    } else {
    delete game;
   }
}


void Arcade::run() {
bool running = true;
while (running) {
    std::cout << "\n====ARCADE MENU===\n";
    for (int i = 0; i < m_count; ++i) {
        std::cout << i + 1 << ". " << m_games[i]->title() << "\n";
  }
  std::cout << m_count + 1 << ". Quit\n";
  std::cout << "Choice: "; 

  int choice = 0;
  if (!(std::cin >> choice)) {
    break;
  }

  if (choice >= 1 && choice <= m_count) {
      int i = choice - 1;
      m_games[i]->play();
    std::cout << "Last score: " << m_games[i]->last_score() <<"\n";
  } else if (choice == m_count + 1) {
    running = false;
  } else {
        std::cout << "Invalid choice. Try again.\n";

     }
   }
}
