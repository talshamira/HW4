
#include <string>
#include <iostream>
#include "Cards/Card.h"
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "Cards/Barfight.h"
#include "Cards/Dragon.h"
#include "Cards/Gremlin.h"
#include "Cards/Mana.h"
#include "Cards/Merchant.h"
#include "Cards/Treasure.h"
#include "Cards/Well.h"
#include "Cards/Witch.h"
#include "utilities.h"
#include <deque>
#include <vector>
#include <map>
#include <memory>
#include <fstream>
#include <queue>

#define MAX_TEAM_SIZE 6


class Mtmchkin{

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

    

    private:
        int initGame();
        int m_numOfRounds;
        std::deque<std::unique_ptr<Card>> m_deck;
        std::vector<std::unique_ptr<Player>> m_players;
        static const int MIN_SIZE_OF_DECK = 5;
        static const int IN_GAME = -1;
        int m_rankings [MAX_TEAM_SIZE];
        int m_winnerPointer;
        int m_looserPointer;
        int m_teamLength;
        int m_numOfWinners;
        int m_numOfLoosers;
};
