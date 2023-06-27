#include <iostream>
#include "../Mtmchkin.h"

int main()
{
    const int MAX_NUM_OF_ROUNDS = 100;
    try {
        Mtmchkin theGame("deck.txt");
        while(!theGame.isGameOver() && theGame.getNumberOfRounds() < MAX_NUM_OF_ROUNDS)
        {
            theGame.playRound();
            theGame.printLeaderBoard();
        }
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 1;
}