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
    int counter = 1;
    std::map<std::string, std::unique_ptr<Card>(*)()> cardMap = getMapOfCards();
    this->m_teamLength = initGame();
    std::ifstream deckFile(filename);
    bool isEmpty = true;
    if(!deckFile)
    {
        throw(DeckFileNotFound());
    }
    while(std::getline(deckFile, lineRead))
    {
        isEmpty = false;
        if(cardMap.find(lineRead) != cardMap.end())
        {
            counter++;
            this->m_deck.push_back(std::move(cardMap[lineRead]()));
        }
        else
        {
            if(lineRead.empty() && counter == 1)
            {
                throw(DeckFileInvalidSize());
            }
            else
            {
                throw(DeckFileFormatError(counter));
            }
        }
    }
    if(isEmpty)
    {
        throw(DeckFileInvalidSize());
    }
    if(counter < MIN_SIZE_OF_DECK)
    {
        throw(DeckFileInvalidSize());
    }
    
    for(int i = 0; i < this->m_teamLength; i++)
    {
        std::string name, job;
        getInputs(name, job);
        this->m_players.push_back(std::move(initPlayer(job, name)));
        this->m_rankings[i] = IN_GAME;
    }
}

int Mtmchkin::initGame()
{
    printStartGameMessage();

    this->m_numOfRounds = 0;
    this->m_winnerPointer = 1;
    this->m_numOfWinners = 0;
    this->m_numOfLoosers = 0;
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
                    this->m_numOfWinners++;
                }
                else if((*player).isKnockedOut())
                {
                    this->m_rankings[counter] = m_looserPointer--;
                    this->m_numOfLoosers++;
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
    return m_numOfLoosers+m_numOfWinners == m_teamLength;
}


void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    int searchFor = 1;
    bool flag = true;
    while (searchFor <= this->m_teamLength && flag)
    {
        flag = false;
        for(int i = 0; i < this-> m_teamLength; i++)
        {
            if(this->m_rankings[i] == searchFor)
            {
                printPlayerLeaderBoard(searchFor, *(m_players[i]));
                searchFor++;
                flag = true;
                continue;
            }
        }
    }
    for(int i = 0; i < this->m_teamLength; i++)
    {
        if(this->m_rankings[i] == this->IN_GAME)
        {
            printPlayerLeaderBoard(searchFor, *(m_players[i]));
            searchFor++;
        }
    }
    while (searchFor <= this->m_teamLength)
    {
        for(int i = 0; i < this-> m_teamLength; i++)
        {
            if(this->m_rankings[i] == searchFor)
            {
                printPlayerLeaderBoard(searchFor, *(m_players[i]));
                searchFor++;
                continue;
            }
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
        if(needToPrintName && !checkName(name))
        {
            printInvalidName();
        }
        else if(needToPrintJob && !checkJob(job))
        {
            printInvalidClass();
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
    return job == "Ninja" || job == "Healer" || job == "Warrior"; 
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

