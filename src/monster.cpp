#include "monster.h"


Monster::Monster(std::string name, int health) 
    : m_name(std::move(name)), m_health(health) {}

std::string Monster::describe() const {
    return m_name + " (health: " + std::to_string(m_health) + ")";
}

void Monster::take_damage(int amount) {
    m_health -= amount;
    if (m_health < 0) {
        m_health = 0;
    }
}

bool Monster::is_dead() const {
    return m_health <= 0;
}

const std::string &Monster::name() const {
    return m_name;
}


Goblin::Goblin() : Monster("Goblin", 10) {}

int Goblin::attack_damage() const {
    return 3;
}

std::string Goblin::describe() const {
    return "A scrawny goblin sneers at you.";
}


Troll::Troll() : Monster("Troll", 20) {}

int Troll::attack_damage() const {
    return 6;
}

std::string Troll::describe() const {
    return "A massive, foul-smelling troll blocks the path.";
}
