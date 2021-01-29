#include <iostream>
#include "stdlib.h"
#include <map>
#include "game.h"
#include "./RogueHack/pers.h"

int game::keyEvent(){
    if( !initialized){
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }
    int bytesWaiting;
    //int bytesWaiting;                                                                                                                                                        
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
};

void game::frameSleep(const int& ms){
    clock_t end;
    end = clock() + ms * CLOCKS_PER_SEC/1000;
    while( clock() < end){
        // wait 
    }
};

std::pair<int,int> game::from_key_to_move(int key){
    if ( key == 68 ) {//flèche gauche
        return std::make_pair(-1,0);
    }
    if ( key == 67 ) {//flèche droite
        return std::make_pair(1,0);
    }
    if ( key == 65 ) {//flèche basse
        return std::make_pair(0,-1);
    }
    if ( key == 66 ) {//flèche haute
        return std::make_pair(0,1);
    }
    return std::make_pair(0,0);
};

void game::startGame( board &b ){
    int key; //variable contenant la frappe
    /*std::pair<int, int> dim = b.get_dim();
    int nx = dim.first;
    int ny = dim.second;*/
    //o.create();
    //b.add_object( a );
    Hero h(40,5);
    while( true ){
        frameSleep(lap);
        if( keyEvent() ){
            int a = getchar();
            int b = getchar();
            int key = getchar(); //récupération de la frappe (3ème caractère pour différencier les flèches)
            h.move( from_key_to_move(key).first, from_key_to_move(key).second ); //maj du mouvement
        }
        b.backgroundClear();
        b.remove_perso( h );
        b.add_perso( h ); //ajout du perso au plateau
        b.printFrame( h ); //affichage du plateau
    };
};