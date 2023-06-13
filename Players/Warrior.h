#ifndef WARRIOR_H_
#define WARRIOR_H_
#include "Player.h"

class Warrior : public Player
{
    public:
        /*
         * constructor - initializes all parameters to the defults:
         * hp = 100 , coins = 10, force = 5
         * and gives the warrior a name based on given name
         * @param name - given name
         */
        Warrior(const std::string name);

         /*
         * virtual get function derived from player
         * returns "Warrior"
         * @return - returns the type of player (Ninja, Healer, Warrior)
         */
        std::string Warrior::getJob() const;

        /*
         * virtual get function derived from Player
         * @returns twice the attack strength meaning return 2*strength + level;
         */
        int getAttackStrength() const;
};


#endif