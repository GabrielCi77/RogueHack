#pragma once
#include <iostream>
#include "stdlib.h"
#include "sys/ioctl.h"
#include "termios.h"
#include "stdio.h"
#include "time.h"
#include <map>
#include "board.h"
#include "pers.h"

class game
{
    public:
 
    int keyEvent(); //détecte la frappe de clavier
    void frameSleep( const int& ms ); //mise en sommeil
    void startGame( board &b );//fonction maîtresse de lancement et gestion du jeu - contient la boucle while(true)
    std::pair<int,int> from_key_to_move(int key);

    private:

    static const int STDIN=0;
    bool initialized=false;
    int lap=200;
};