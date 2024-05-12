#include "Automata.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

Automata::Automata() : cash(0), state(STATES::OFF) {}

void Automata::on()
{
    state = STATES::ON;
}

void Automata::off()
{
    state = STATES::OFF;
}

void Automata::coin(int amount)
{
    cash += amount;
    state = STATES::COIN;
}

void Automata::etMenu(const std::string &filename)
{
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            menu.push_back(line);
            getline(file, line);
            prices.push_back(std::stoi(line));
        }
        file.close();
        state = STATES::ET_MENU;
    }
    else
    {
        std::cout << "Файл не найден." << std::endl;
    }
}

STATES Automata::getState()
{
    return state;
}

void Automata::choice(int index)
{
    if (index >= 0 && index < menu.size())
    {
        cash -= prices[index];
        state = STATES::CHECK;
    }
    else
    {
        std::cout << "Неверный индекс напитка." << std::endl;
    }
}

void Automata::check()
{
    if (cash >= prices[menu.size() - 1])
    {
        state = STATES::COOK;
    }
    else
    {
        std::cout << "Недостаточно средств." << std::endl;
    }
}

void Automata::cancel()
{
    cash = 0;
    state = STATES::CANCEL;
}

void Automata::cook()
{
    std::cout << "Напиток готовится..." << std::endl;
    state = STATES::COOK;
}

void Automata::finish()
{
    cash = 0;
    state = STATES::OFF;
}
