#ifndef NINJA_H_HW4
#define NINJA_H_HW4
#include "Player.h"

class Ninja : public Player 
{
    public:
        /*
         *constructor - creates a player of the type Ninja
         * Initializes the player's hp to the max hp (100) and the player's force to the defualt force (5)
         * @param name - the name of the player
         */
        Ninja(const std::string name);

        /*
         * virtual function derived from Player
         * Ninjas get twice as many coins meaning 2*coinsToAdd
         * @param coinsToAdd - amount to be added
         */
        void addCoins(int coinsToAdd);

        /*
         * virtual get function derived from player
         * returns "Ninja"
         * @return - returns the type of player (Ninja, Healer, Warrior)
         */
        std::string getJob() const;

};
#endif //NINJA_H_HW4