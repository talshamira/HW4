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
private:
    static const int CHOICE_FOR_POTION = 1;
    static const int CHOICE_FOR_BOOST = 2;
    static const int COINS_FOR_POTION = 5;
    static const int COINS_FOR_BOOST = 10;
    static const int BUFF_ADDED = 1;
    static const int HP_TO_ADD = 1;
    void printCard(std::ostream& os) const override;

public:
    void applyEncounter(Player& player) const override;
};


#endif //HW4_MERCHANT_H
