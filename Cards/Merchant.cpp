//
// Created by user on 17/06/2023.
//

#include "Merchant.h"

//TODO: check about os and if need to use getline,stoi
void Merchant::applyEncounter(Player& player) const
{
    int playersChoice;
    printMerchantInitialMessageForInteractiveEncounter(std::cout, player.getName(), player.getCoins());
    std::cin >> playersChoice;
    while (playersChoice != 0 && playersChoice != CHOICE_FOR_POTION && playersChoice != CHOICE_FOR_BOOST)
    {
        printInvalidInput();
        std::cin >> playersChoice;
    }
    int playersCoins = player.getCoins();
    if((playersChoice == CHOICE_FOR_POTION && playersCoins < COINS_FOR_POTION) || (playersChoice == CHOICE_FOR_BOOST && playersCoins < COINS_FOR_BOOST))
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
//printMerchantInitialMessageForInteractiveEncounter