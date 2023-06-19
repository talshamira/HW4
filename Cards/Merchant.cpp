//
// Created by user on 17/06/2023.
//

#include "Merchant.h"

void Merchant::applyEncounter(Player& player) const
{
    int playersChoice, playersCoins = player.getCoins();
    std::string input;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::getline (std::cin,input);
    playersChoice = stoi(input);
    while (playersChoice != 0 && playersChoice != CHOICE_FOR_POTION && playersChoice != CHOICE_FOR_BOOST)
    {
        printInvalidInput();
        std::getline (std::cin,input);
        playersChoice = stoi(input);
    }
    if((playersChoice == CHOICE_FOR_POTION && playersCoins < COINS_FOR_POTION) ||
        (playersChoice == CHOICE_FOR_BOOST && playersCoins < COINS_FOR_BOOST))
    {
        printMerchantInsufficientCoins(std::cout);
        printMerchantSummary(std::cout, player.getName(), playersChoice, 0);
        return;
    }
    switch (playersChoice) {
        case 0:
            printMerchantSummary(std::cout, player.getName(), playersChoice, 0);
            break;
        case CHOICE_FOR_POTION:
            printMerchantSummary(std::cout, player.getName(), playersChoice, COINS_FOR_POTION);
            break;
        case CHOICE_FOR_BOOST:
            printMerchantSummary(std::cout, player.getName(), playersChoice, COINS_FOR_BOOST);
            break;
    }
}

void Merchant::printCard(std::ostream& os) const
{
    printCardDetails(os, "Merchant");
}
