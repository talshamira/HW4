#ifndef HEALER_H_
#define HEALER_H_
#include "Player.h"

class Healer : public Player
{
    public:
        /*
         * constuctor for Healer initializes all paramaters to defaults given:
         * hp = 100, coins = 10, force = 5
         * @param name the player's name
         */
        Healer(const std::string name);

        /*
         * virtual function derived from Player
         * heals the healer by twice the given amount
         * @param hpToAdd - amount of hp given
         */
        void heal(int hpToAdd) override;


         /*
         * virtual get function derived from player
         * returns "Healer"
         * @return - returns the type of player (Ninja, Healer, Warrior)
         */
        std::string getJob() const override;


        /*
         * default functions
         */
        ~Healer() = default;
        Healer& operator=(const Healer& oldHealer) = default;
        Healer(const Healer& oldHealer) = default;
};

#endif