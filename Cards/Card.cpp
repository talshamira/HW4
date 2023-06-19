#include "Card.h"

std::ostream& operator<<(std::ostream& os,const Card& card)
{
    card.printCard(os);
    printEndOfCardDetails(os);
    return os;
}
