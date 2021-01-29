#include "pers.h"
#include <cmath>

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