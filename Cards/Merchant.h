//
// Created by user on 17/06/2023.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>
#include <string>

class Merchant : public Card
{
    public:
       /*
        * default functions
        */
        Merchant() = default;
        ~Merchant() = default;
        Merchant& operator=(const Merchant& merchant) = default;
        Merchant(const Merchant& merchant) = default;
        /*
         * virtual function derived from Cards
         * applys the cards effects on the given player 
         * the merchant offers the player one of his three wares
         * then the merchant sells the chosen ware to the player 
         * if the player has enough money
         * @param player is the player who drew the card
         */
        void applyEncounter(Player& player) const override;
    private:
        static const int CHOICE_FOR_POTION = 1;
        static const int CHOICE_FOR_BOOST = 2;
        static const int COINS_FOR_POTION = 5;
        static const int COINS_FOR_BOOST = 10;
        static const int BUFF_ADDED = 1;
        static const int HP_TO_ADD = 1;
        /*
         * virtual print function derived from card
         * prints the specific details for Merchant
         * @PARAM os is the output stream 
         */
        void printCard(std::ostream& os) const override;


};


#endif //HW4_MERCHANT_H
