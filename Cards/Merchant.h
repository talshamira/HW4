//
// Created by user on 17/06/2023.
//

#ifndef HW4_MERCHANT_H
#define HW4_MERCHANT_H
#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Merchant : public Card
{
public:
    static const int CHOICE_FOR_POTION = 1;
    static const int CHOICE_FOR_BOOST = 2;
    static const int COINS_FOR_POTION = 5;
    static const int COINS_FOR_BOOST = 10;

    void applyEncounter(Player& player) const override;
};


#endif //HW4_MERCHANT_H
