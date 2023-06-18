#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <string>
#include <iostream>
#include "Cards/Cards.h"
#include "Players/Player.h"
#include "Players/Healer.h"
#include "Players/Ninja.h"
#include "Players/Warrior.h"
#include "utilities.h"
#include <queue>
#include <list>
#include <map>
#include <memory>
#include <fstream>

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
        int m_numOfRounds;
        std::queue<std::unique_ptr<Cards>> m_deck;
        std::list<std::unique_ptr<Player>> m_players;
        static const int MIN_SIZE_OF_DECK = 5;

        int getTeamSize();
};



#endif /* MTMCHKIN_H_ */
