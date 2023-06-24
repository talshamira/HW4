//
// Created by user on 13/05/2023.
//

#include "Player.h"
#include "../utilities.h"


Player::Player(std::string name) :
    m_name(name),
    m_HP(DEFAULT_MAX_HP),
    m_coins(DEFAULT_COINS),
    m_level(1),
    m_force(DEFAULT_FORCE)
{}

std::ostream& operator<<(std::ostream& os,const Player& player)
{
    printPlayerDetails(os,player.m_name.c_str(),player.getJob(), player.m_level, player.m_force, 
                                                                                player.m_HP,player.m_coins);
    return os;
}

void Player::levelUp() {
    if(this->m_level < MAX_LEVEL)
    {
        this->m_level++;
    }
}

int Player::getLevel() const {
    return this->m_level;
}

void Player::buff(int forceToAdd) {
    if(forceToAdd > 0)
    {
        this->m_force += forceToAdd;
    }
}

void Player::heal(int hpToAdd) {
    if(hpToAdd > 0)
    {
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

void Player::damage(int hpToDiminish) {
    if(hpToDiminish > 0)
    {
        if(hpToDiminish >= this->m_HP)
        {
            this->m_HP = 0;
        }
        else
        {
            this->m_HP -= hpToDiminish;
        }
    }
}

bool Player::isKnockedOut() const {
    if(this->m_HP <= 0)
    {
        return true;
    }
    return false;
}

void Player::addCoins(int coinsToAdd) {
    if(coinsToAdd > 0)
    {
        this->m_coins += coinsToAdd;
    }  
}

bool Player::pay(int coinsToPay) {
    if(coinsToPay > 0)
    {
        if(coinsToPay <= this->m_coins)
        {
            this->m_coins -= coinsToPay;
            return true;
        }
        return false;
    }
    return true;
}

int Player::getAttackStrength() const {
    return (this->m_level + this->m_force);
}

std::string Player::getName() const
{
    return this->m_name;
}

int Player::getCoins() const
{
    return this->m_coins;
}

void Player::killPlayer()
{
    this->m_HP = 0;
}

void Player::weakPlayer()
{
    if(this->m_force > 0)
    {
        this->m_force--;
    }
    else
    {
        this->m_force = 0;
    }
}