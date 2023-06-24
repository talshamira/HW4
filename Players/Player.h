//
// Created by user on 13/05/2023.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <iostream>
#include <string>



class Player {

public:
    static const int MAX_LEVEL = 10;
    static const int DEFAULT_COINS = 10;
    static const int DEFAULT_MAX_HP = 100;
    static const int DEFAULT_FORCE = 5;

    //Constractor. get from the user name.
    //The default values: maxHP - 100, force - 5;
    Player(std::string name);

    //default destractor, copy constractor and operator=.
    virtual ~Player() = default;
    Player(const Player&) = default;
    Player & operator=(const Player &) = default;

    //Prints players details: name, level, force, HP and coins.
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    //Level up the players level.
    void levelUp();

    //Returns the players level.
    int getLevel() const;

    //Gets points to add to force and adds them.
    void buff(int forceToAdd);

    //get points to add to hp and adds them. make sure the current hp isnt higher then maxHP.
    virtual void heal(int hpToAdd);

    //Gets hp to diminish from player and diminishes it. If the result is negative, change to 0.
    void damage(int hpToDiminish);

    //Returns true if hp is 0 and false otherwise.
    bool isKnockedOut() const;

    //Gets amount of coins to add to the player and adds them.
    virtual void addCoins(int coinsToAdd);

    //Gets amount pf coins that the player needs to play (diminish from his coins).
    //Returns true if the player has coins to pay and false otherwise.
    bool pay(int coinsToPay);

    //Returns the attack strength. attack strength = force + level
    virtual int getAttackStrength() const;

    //Returns the name of the player
    std::string getName() const;

    //Returns the coins of the player
    int getCoins() const;

    //reduce the hp of the player to 0
    void killPlayer();

    //reduce the force of the player in 1 force
    void weakPlayer();

    //returns the job of the player - Ninja Warrior or Healer
    virtual std::string getJob() const = 0;


private:
    std::string m_name; 
protected:
    int m_HP;
    int m_coins;
    int m_level;
    int m_force;
};


#endif //EX4_PLAYER_H
