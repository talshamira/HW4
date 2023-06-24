#include "Warrior.h"

Warrior::Warrior(const std::string name): Player(name){}

std::string Warrior::getJob() const
{
    return "Warrior";
}

int Warrior::getAttackStrength() const
{
    return (this->m_level + (this->m_force*2));
}


