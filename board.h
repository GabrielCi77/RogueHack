#pragma once
#include <iostream>
#include <map>
#include "stdlib.h"
#include "./RogueHack/pers.h"

class board {

    public:
        board();
        void backgroundClear();
        void printFrame();
        void printFrame( person p );
        //void add_object( objet o );
        //void remove_object( objet o );
        void add_perso( person p );
        void remove_perso( person p );

    private:
        std::map<std::pair<int, int>, int> boardgame;
        int nx = 50;
        int ny = 25;
        const char* cmd_clear="clear";
};