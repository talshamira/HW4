#include "Mtmchkin.h"

static const int MIN_SIZE_OF_TEAM = 2;
static const int MAX_SIZE_OF_TEAM = 6;
static const int MAX_LENGTH_NAME = 15;
static const std::string SPACER = " ";
bool checkName(std::string name);
bool checkJob(std::string job);
void getInputs(std::string& name, std::string& job);
std::map<std::string ,std::unique_ptr<Card>(*)()> getMapOfCards();
std::unique_ptr<Player> initPlayer( const std::string& job,const  std::string& name);
int getTeamSize();



Mtmchkin::Mtmchkin(const std::string &filename)
{
    std::string lineRead;
    int counter = 0;
    std::map<std::string, std::unique_ptr<Card>(*)()> cardMap = getMapOfCards();
    this->m_teamLength = initGame();
    try {
        std::ifstream deckFile(filename);
        while(std::getline(deckFile, lineRead))
        {
            if(cardMap.find(lineRead) != cardMap.end())//TODO check if line numbers start at 0 or 1
            {
                counter++;
                this->m_deck.push_front(std::move(cardMap[lineRead]()));
            }
            else
            {
                if(lineRead.empty() && counter == 0)
                {
                    throw(DeckFileInvalidSize());
                }
                else
                {
                    throw(DeckFileFormatError(counter));
                }
            }
        }
    }
    catch (...) {
        throw(DeckFileNotFound());
    }

    if(counter < MIN_SIZE_OF_DECK)
    {
        throw(DeckFileInvalidSize());
    }
    
    for(int i = 0; i < this->m_teamLength; i++)
    {
        std::string name, job;
        getInputs(name, job);
        try
        {
            this->m_players.push_back(std::move(initPlayer(job, name)));
        }
        catch(...)
        {
            throw(std::bad_alloc());// dont know what to throw
        }
        this->m_rankings[i] = IN_GAME;
    }

}

int Mtmchkin::initGame()
{
    printStartGameMessage();

    this->m_numOfRounds = 0;
    this->m_winnerPointer = 1;

    int teamSize = getTeamSize();
    this->m_looserPointer = teamSize;

    return teamSize;
}

std::unique_ptr<Player> initPlayer( const std::string& job,const  std::string& name)
{
    std::unique_ptr<Player> tempPlayer;
    if(!job.compare("Ninja"))
    {
        tempPlayer.reset(new Ninja(name));
    }
    else if(!job.compare("Healer"))
    {
        tempPlayer.reset(new Healer(name));
    }
    else
    {
        tempPlayer.reset(new Warrior(name));
    }

    return tempPlayer;
}

void Mtmchkin::playRound()
{
    if(!isGameOver())
    {
        int counter = 0; 
        this->m_numOfRounds++;
        printRoundStartMessage(this->m_numOfRounds);
        for(std::unique_ptr<Player>& player : this->m_players)
        {
            if(this->m_rankings[counter] == -1)
            {
                printTurnStartMessage(player->getName());
                this->m_deck.front()->applyEncounter(*player);
                this->m_deck.push_back(std::move(m_deck.front()));
                this->m_deck.pop_front();
                if((*player).getLevel() == player->MAX_LEVEL)
                {
                    this->m_rankings[counter] = m_winnerPointer++;
                }
                else if((*player).isKnockedOut())
                {
                    this->m_rankings[counter] = m_looserPointer--;
                }
            }
            counter++;
        }   
    }
    if(isGameOver())
    {
        printGameEndMessage();
    }
}

bool Mtmchkin::isGameOver() const
{
    int teamLength =  this->m_winnerPointer+ this->m_looserPointer;
    for(int i = 0; i < teamLength; i++)
    {
        if(this->m_rankings[i] == -1)
        {
            return false;
        }
    }
    return true;
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int searchFor = 1;
    bool stillInPlay = false;
    bool found[m_teamLength];
    for(int i = 0; i < m_teamLength; i++)
    {
        found[i] = false;
    }
    while(searchFor <= this->m_teamLength && !stillInPlay)
    {
        int counter = 0;
        while(counter < this->m_teamLength && this->m_rankings[counter] != searchFor)
        {
            counter++;
        }
        if(counter < this->m_teamLength && !found[counter])
        {
            printPlayerLeaderBoard(m_rankings[counter], *(m_players[counter]));
            searchFor++;
            found[counter] = true;
        }
        else
        {
            stillInPlay = true;
        }
    }
    for(int i = 0; i < m_teamLength; i++)
    {
        if(!found[i])
        {
            printPlayerLeaderBoard(searchFor, *(m_players[i]));
            searchFor++;
        }
    }

}
 int Mtmchkin::getNumberOfRounds() const
 {
    return this->m_numOfRounds;
 }

void getInputs(std::string& name, std::string& job)
{
    printInsertPlayerMessage();
    std::string input;
    bool needToPrintName = false, needToPrintJob = false;
    while(!checkName(name) || !checkJob(job))
    {
        if(needToPrintName && checkName(name))
        {
            printInvalidName();
            printInsertPlayerMessage();
        }
        if(needToPrintJob && checkJob(job))
        {
            printInvalidClass();
            printInsertPlayerMessage();
        }
        try
        {
            std::getline(std::cin, input);
            name = input.substr(0,input.find(SPACER));
            job = input.substr(input.find(SPACER)+1, input.size());
        }
        catch(...)
        {
            printInvalidInput();
            printInsertPlayerMessage();
            needToPrintJob = false;
            needToPrintName = false;
        }
        needToPrintJob = true;
        needToPrintName = true;
    } 
}

bool checkName(std::string name)
{
    if (name.length() > MAX_LENGTH_NAME || name.empty())
    {
        return false;
    }
    for(char c : name)
    {
        if(!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
        {
            return false;
        }
    }
    return true;
}

bool checkJob(std::string job)
{
    return job.compare("Ninja") || job.compare("Healer") || job.compare("Warrior"); 
}

int getTeamSize()
{
    printEnterTeamSizeMessage();
    std::string input;
    int teamSize  = 0;
    bool needPrint = false;
    while(teamSize < MIN_SIZE_OF_TEAM || teamSize > MAX_SIZE_OF_TEAM)
    {
        if(needPrint)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
        try
        {
            std::getline(std::cin , input);
            teamSize = std::stoi(input);
        }
        catch(...)
        {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
            needPrint = false;
        }
        needPrint = true;
    }
    return teamSize;
}

template <class T>
std::unique_ptr<Card> cardTemplateCreate()
{
    std::unique_ptr<Card> newCard(new T);
    return newCard; 
}

std::map<std::string ,std::unique_ptr<Card>(*)()> getMapOfCards()
{
    std::map<std::string, std::unique_ptr<Card>(*)()> mapOfCards;
    mapOfCards["Gremlin"] = &cardTemplateCreate<Gremlin>;
    mapOfCards["Witch"] = &cardTemplateCreate<Witch>;
    mapOfCards["Dragon"] = &cardTemplateCreate<Dragon>;
    mapOfCards["Merchant"] = &cardTemplateCreate<Merchant>;
    mapOfCards["Treasure"] = &cardTemplateCreate<Treasure>;
    mapOfCards["Well"] = &cardTemplateCreate<Well>;
    mapOfCards["Barfight"] = &cardTemplateCreate<Barfight>;
    mapOfCards["Mana"] = &cardTemplateCreate<Mana>;
    return mapOfCards;
}

