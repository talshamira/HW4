//
// Created by user on 17/06/2023.
//

#ifndef HW4_BARFIGHT_H
#define HW4_BARFIGHT_H

#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Barfight : public Card
{
    public:
        static const int POINTS_TO_DIMINISH = 10;
        /*
         * default functions
         */
        Barfight() = default;
        ~Barfight() = default;
        Barfight& operator=(const Barfight& barfight) = default;
        Barfight(const Barfight& barfight) = default;
        /*
         * virtual function derived from Cards
         * applys the cards effects on the given player 
         * if the player is a warrior then nothing happens otherwise the player looses 10 hp
         * @param player is the player who drew the card
         */
        void applyEncounter(Player& player) const override;
    private:
        /*
         * virtual print function derived from card
         * prints the specific details for Barfight
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;
};

#endif //HW4_BARFIGHT_H
