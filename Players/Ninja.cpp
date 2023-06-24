#include "Ninja.h"

Ninja::Ninja(const std::string name) : Player(name) {}

void Ninja::addCoins(int coinsToAdd) {
    if(coinsToAdd > 0)
    {
        this->m_coins += 2*coinsToAdd;
    }  
}

std::string Ninja::getJob() const
{
    return "Ninja";
}