//
// Created by user on 17/06/2023.
//

#ifndef HW4_WELL_H
#define HW4_WELL_H


#include "Card.h"
#include "../Players/Player.h"
#include "../utilities.h"
#include <ostream>


class Well : public Card
{
public:
    static const int POINTS_TO_DIMINISH = 10;
    /*
     * default functions
     */
    Well() = default;
    ~Well() = default;
    Well& operator=(const Well& well) = default;
    Well(const Well& well) = default;
    /*
     * virtual function derived from Cards
     * applys the cards effects on the given player 
     * if the player is not a Ninja than the player looses 10 hp otherwise nothing happens
     * @param player is the player who drew the card
     */
    void applyEncounter(Player& player) const override;

private:
    /*
     * virtual print function derived from card
     * prints the specific details for Well
     * @PARAM os is the output stream 
     */
    void printCard(std::ostream& os) const override;
};

#endif //HW4_WELL_H
