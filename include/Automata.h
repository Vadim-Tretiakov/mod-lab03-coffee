// Copyright [year] <Copyright Owner>

#ifndef INCLUDE_AUTOMATA_H_
#define INCLUDE_AUTOMATA_H_

#include <vector>
#include <string>
#include <fstream>

enum STATES {
    OFF,
    ON,
    COIN,
    ET_MENU,
    GET_STATE,
    CHOICE,
    CHECK,
    CANCEL,
    COOK,
    FINISH
};

class Automata {
    public:
        int cash;
        std::vector<std::string> menu;
        std::vector<int> prices;
        STATES state;

        Automata();

        void on();

        void off();

        void coin(int amount);

        void etMenu(const std::string& filename);

        STATES getState();

        void choice(int index);

        void check();

        void cancel();

        void cook();

        void finish();

        friend class AutomataTest;
};

#endif  // INCLUDE_AUTOMATA_H_
