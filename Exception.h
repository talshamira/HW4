#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <exception>
#include <iostream>

class DeckFileNotFound : public  std::exception
{
    public:
        const char* what() const noexcept override
        {
            return "Deck File Error: File not found";
        }
};

class DeckFileFormatError : public std::exception
{
    public:
        DeckFileFormatError(const int line) : 
        m_message("Deck File Error: File format error in line")
        {
            this->m_message += std::to_string(line);
        }
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
        const char* what() const noexcept override
        {
            return "Deck File Error: Deck size is invalid";
        }
};

#endif