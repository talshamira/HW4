#include "Mtmchkin.h"

static const int MIN_SIZE_OF_TEAM = 2;
static const int MAX_SIZE_OF_TEAM = 6;
static const int MAX_LENGTH_NAME = 15;
static const std::string SPACER = " ";
bool checkName(std::string name);
bool checkJob(std::string job);
void getInputs(std::string name, std::string job);
std::map<std::string ,std::unique_ptr<Card>(*)()> getMapOfCards();
int getTeamSize();



Mtmchkin::Mtmchkin(const std::string &filename)
{
    printStartGameMessage();
    std::ifstream deckFile(filename);
    if(!deckFile || deckFile.is_open())
    {
        throw(DeckFileNotFound());
    }
    std::string lineRead;
    int counter = 0;
    std::map<std::string, std::unique_ptr<Card>(*)()> cardMap = getMapOfCards();
    while(std::getline(deckFile, lineRead))
    {
        //TODO check if line numbers start at 0 or 1
        if(cardMap.find(lineRead) != cardMap.end())
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
    if(counter < MIN_SIZE_OF_DECK)
    {
        throw(DeckFileInvalidSize());
    }
    int teamsize = getTeamSize();
    std::string name, job;
    for(int i = 0; i < teamsize; i++)
    {
        getInputs(name, job);
        try
        {
            std::unique_ptr<Player> tempPlayer;
            if(job.compare("Ninja"))
            {
                tempPlayer.reset(new Ninja(name));
                this->m_players.push_back(tempPlayer);
            }
            else if(job.compare("Healer"))
            {
                tempPlayer.reset(new Healer(name));
                this->m_players.push_back(tempPlayer);
            }
            else
            {
                tempPlayer.reset(new Warrior(name));
                this->m_players.push_back(tempPlayer);
            }
        }
        catch(...)
        {
            throw(std::bad_alloc());// dont know what to throw
        }
    }
    this->m_numOfRounds = 0;
    this->m_winnerPointer = 1;
    this->m_looserPointer = teamsize;
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
                this->m_deck.push_back(this->m_deck.front());
                this->m_deck.pop_front();
                if(player->getLevel() == player->MAX_LEVEL)
                {
                    this->m_rankings[counter] = m_winnerPointer++;
                }
                else if(player->isKnockedOut())
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
    int teamLength = this->m_looserPointer + this->m_winnerPointer;
    int searchFor = 1;
    while(searchFor != teamLength)
    {
        int counter = 0;
        while(counter < teamLength && this->m_rankings[counter] != searchFor)
        {
            counter++;
        }
        printPlayerLeaderBoard(this->m_rankings[counter], *this->m_players[counter]);
        searchFor++;
    }
}
 int Mtmchkin::getNumberOfRounds() const
 {
    return this->m_numOfRounds;
 }

void getInputs(std::string name, std::string job)
{
    printInsertPlayerMessage();
    std::string input;
    bool needToPrintName = false, needToPrintJob = false;
    while(checkName(name) || checkJob(job))
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
    if (name.length() > MAX_LENGTH_NAME)
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

