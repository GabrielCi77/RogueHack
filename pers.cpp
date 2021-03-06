#include "pers.h"
#include <cmath>
#include "objet.h"

bool person::assezproche(person* H,person* L){
    int por=H->portee;
    int x1= H->coord.first;
    int y1= H->coord.second;
    int x2= L->coord.first;
    int y2= L->coord.second;
    if(abs(x2-x1)<=portee and abs(y2-y1)<=portee){
        return true;
    }
    return false;
}

bool Hero::surobjet(Objet* B){
    int x1= getpos().first;
    int y1= getpos().second;
    int x2= B->GetPos().first;
    int y2= B->GetPos().second;
    if(abs(x2-x1)==0 and abs(y2-y1)==0){
        return true;
    }
    return false;
}

void enemy::attaque(Hero* H, vector< enemy* > L){
        for(int i=0;i<L.size();i++){
            if (assezproche(H,L[i]))
                H->hit(L[i]->str);
        }
    }

void enemy::die(Hero* H){
        H->plusexp(expgiven);
}