#include <iostream>

#include "board.h"
#include "game.h"
#include "./RogueHack/pers.h"

int main(){
    board board_basic;
    game g;

    g.startGame( board_basic );

    return 0;
}