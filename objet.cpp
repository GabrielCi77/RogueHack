#include <iostream>
#include "stdlib.h"

class Objet{
public:
    Objet(std::pair<int, int> pos):pos(pos){
        type[0] = Symbole;
        type[1] = Valeur;
    }

    Objet(int x, int y){
        pos = std::make_pair(x, y);
    }
    std::pair<int, int> GetPos(){
        return pos;
    }

    int GetChar(){
        return Symbole;
    }
    int GetPoids(){
        return Poids;
    }
    int GetVal(){
        return Valeur;
    }

    int* TakeObjet(){
        return type;
    }

protected:
    int Valeur; // pour une piece : valeur de la piece, pour une potion : nombre de coeur qu'elle restaure
    int Poids; //Place prise par l'objet dans l'inventaire
    std::pair<int, int> pos; //position sur le plateau
    char Symbole; // $ pour une piece, p pour une potion
    int type[];
};

    class Piece : public Objet{
    public:
        Piece(std::pair<int, int> pos): Objet(pos){
            Symbole='$';
            Poids=1; // le poids est 1 pour toutes les pieces
        }
        //Deuxieme constructeur si on rentre deux entiers au lieu d'une paire
        Piece(int x, int y): Objet(x, y){
            Symbole='$';
            Poids=1;
        }
    };

        class PetitePiece : public Piece{
        public:
            PetitePiece(std::pair<int, int> pos):Piece(pos){
                Valeur=1; // La valeur des petites pieces est 1$
            }
        };

        class GrandePiece : public Piece{
        public:
            GrandePiece(std::pair<int, int> pos):Piece(pos){
                Valeur=5; // La valeur des petites pieces est 5$
            }
        };

    class Potion : public Objet{
    public:
        Potion(std::pair<int, int> pos): Objet(pos){
            Poids=2;
        }
    };

        class PetitePotion : public Potion{
        public:
            PetitePotion(std::pair<int, int> pos): Potion(pos){
                Valeur=5;
                Symbole='p';
            }
        };
        class GrandePotion : public Potion{
        public:
            GrandePotion(std::pair<int, int> pos): Potion(pos){
                Valeur=10;
                Symbole='P';
            }
        };

    class Armure : public Objet{
    public:
        Armure(std::pair<int, int> pos): Objet(pos){
        }
    };

        class Casque : public Armure{
            public:
            Casque(std::pair<int, int> pos): Armure(pos){
                Valeur=2;
                Poids=1;
                Symbole='c';
            }
        };

        class Plastron : public Armure{
            public:
            Plastron(std::pair<int, int> pos): Armure(pos){
                Valeur=5;
                Poids=2;
                Symbole='&';
            }
        };

    class Arme : public Objet{
    public:
        Arme(std::pair<int, int> pos): Objet(pos){
            Symbole='!';
        }
    };

        class EpeeBois : Arme{
        public:
            EpeeBois(std::pair<int, int> pos): Arme(pos){
                Valeur=2;
                Poids=1;
            }
        };

        class EpeeLegende : Arme{
        public:
            EpeeLegende(std::pair<int, int> pos): Arme(pos){
                Valeur=5;
                Poids=2;
            }
        };

/* int main(){
    std::pair<int, int> pos = std::make_pair(1, 1);
    PetitePiece p1(pos);
    std::cout << p1.GetChar() << " " << p1.GetPoids() << " " << p1.GetVal() << std::endl;
    int sal[2];
    sal[0] = p1.TakeObjet()[0];
    sal[1] = p1.TakeObjet()[1];
    std::cout << sal[0] << " " << sal[1] << std::endl;
    //Piece essai(10,1,1);
    //Piece salut(10,pos);
    //Arme armee(12,pos);
    return 0;
} */