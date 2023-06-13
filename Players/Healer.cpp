#include "Healer.h"

Healer::Healer(const std::string name): Player(name){};

void Healer::heal(int hpToAdd)
{
    if(hpToAdd > 0)
    {
         hpToAdd *=2;
        if(this->m_HP + hpToAdd <= this->DEFAULT_MAX_HP)
        {
            this->m_HP += hpToAdd;
        }
        else
        {
            this->m_HP = this->DEFAULT_MAX_HP;
        }
    }
}

std::string Healer::getJob() const
{
    return "Healer";
}
