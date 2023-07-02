#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <iostream>

class DeckFileNotFound : public  std::exception
{
    public:
        /*
         * overide to the what function from std::exception 
         * returns the appropriate string 
         */
        const char* what() const noexcept override
        {
            return "Deck File Error: File not found";
        }
        /*
         * default functions
         */
        DeckFileNotFound() = default;
        ~DeckFileNotFound() = default;
        DeckFileNotFound& operator= (const DeckFileNotFound& deckFileNotFound) = default;
        DeckFileNotFound(const DeckFileNotFound& deckFileNotFound) = default;
};

class DeckFileFormatError : public std::exception
{
    public:
        /*
         * constructor for the DeckFileFormatError
         * initiates the message to the appropriate message to be used by the what function
         */
        DeckFileFormatError(const int line) : 
        m_message("Deck File Error: File format error in line ")
        {
            this->m_message += std::to_string(line);
        }
        /*
         * default functions
         */
        ~DeckFileFormatError() = default;
        DeckFileFormatError& operator= (const DeckFileFormatError& deckFileFormatError) = default;
        DeckFileFormatError(const DeckFileFormatError& deckFileFormatError) = default;
        /*
         * overide to the what function from std::exception 
         * returns the appropriate string 
         */
        const char* what() const noexcept override
        {
            return this->m_message.data();
        }
    private:
        std::string m_message;
};

class DeckFileInvalidSize : public std::exception
{
    public:
        /*
         * default functions
         */
        DeckFileInvalidSize() = default;
        ~DeckFileInvalidSize() = default;
        DeckFileInvalidSize& operator= (const DeckFileInvalidSize& deckFileInvalidSize) = default;
        DeckFileInvalidSize(const DeckFileInvalidSize& deckFileInvalidSize) = default;
        /*
         * overide to the what function from std::exception 
         * returns the appropriate string 
         */
        const char* what() const noexcept override
        {
            return "Deck File Error: Deck size is invalid";
        }
};

#endif