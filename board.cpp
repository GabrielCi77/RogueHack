#include <iostream>
#include <map>
#include "stdlib.h"
#include "pers.h"

#include "board.h"


//version débutante :  on crée un donjon facile (faut pas chercher à comprendre toutes les boucles,
//c'est juste long et chiant)
board::board(){
    //verticales
    int x = 1;
    for ( int y = 16; y<26; y++ ){
        boardgame[std::make_pair(x, y)] = 0;
    }
    x = 20;
    for ( int y = 16; y<26; y++ ){
        boardgame[std::make_pair(x, y)] = 0;
    }
    x = 31;
    for ( int y = 1; y<11; y++ ){
        boardgame[std::make_pair(x, y)] = 0;
    }
    x = 50;
    for ( int y = 1; y<11; y++ ){
        boardgame[std::make_pair(x, y)] = 0;
    }
    //horizontales
    int y = 25;
    for ( int i = 15; i<21; i++ ){
        boardgame[std::make_pair(i, y)] = 1;
    }
    y = 25;
    for ( int i = 1; i<21; i++ ){
        boardgame[std::make_pair(i, y)] = 1;
    }
    y = 15;
    for ( int i = 1; i<21; i++ ){
        boardgame[std::make_pair(i, y)] = 1;
    }
    y = 10;
    for ( int i = 31; i<51; i++ ){
        boardgame[std::make_pair(i, y)] = 1;
    }
    y = 1;
    for ( int i = 31; i<51; i++ ){
        boardgame[std::make_pair(i, y)] = 1;
    }
    //chemin
    x = 7;
    for ( int j = 15; j>5; j-- ){
        boardgame[std::make_pair(x, j)] = 2;
    }
    y = 6;
    for ( int i = 7; i<31; i++ ){
        boardgame[std::make_pair(i, y)] = 2;
    }
    boardgame[std::make_pair(7, 15)] = 3;
    boardgame[std::make_pair(31, 6)] = 3;
    //cases vides
    for ( int i=2; i<20; i++ ){
        for ( int j=17; j<25; j++ ){
            boardgame[std::make_pair(i, j)] = -1;
        }
    }
    for ( int i=32; i<50; i++ ){
        for ( int j=2; j<10; j++ ){
            boardgame[std::make_pair(i, j)] = -1;
        }
    }
}

void board::backgroundClear(){
    int out = system( cmd_clear);
    if( out != 0){
        std::cerr << "clear command failed" << std::endl;
        exit(1);
    }
};

void board::printFrame( person p ){
    for( int j=0; j<ny; j++){
        for( int i=0; i<nx; i++){
            std::map<std::pair<int, int>,int>::iterator it; //it est de type iterator
            it = boardgame.find(std::make_pair(i,j));  //renvoie l'itérable correspondant à la clef et map.end() si pas cette clef dans dico
            if (it->second == 0){std::cout << "|";} //affihe le bord
            else if (it->second == 1){std::cout << "-";}
            else if (it->second == 2){std::cout << "#";}
            else if (it->second == 3){std::cout << "+";}
            else if ( it == boardgame.end()){std::cout << " ";} //pas la clef dans le dico - affiche du vide
            else if (it->second == p.getchar()){std::cout << p.getchar();}
        };
        std::cout << std::endl;
    };
};

/*void board::add_object( objet o ){
    //itère sur tout l'objet et ajoute l'étiquette objet au plateau
    boardgame[o.position()] = o.get_label();
};

void board::remove_object( objet o ){
    //supprime du plateau (donc du dictionnaire) tous les éléments de l'objet
    boardgame.erase(o.position());
};*/

void board::add_perso( person p ){
    //itère sur tout le perso et ajoute l'étiquette perso au plateau
    boardgame[p.getpos()] = p.getchar();
};

void board::remove_perso( person p ){
    //supprime du plateau (donc du dictionnaire) tous les éléments du perso
    boardgame.erase(p.getpos());
};