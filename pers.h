#include <utility>
#include <cmath>
#include <vector>
#include "objet.cpp"

using namespace std;

class Hero;

class person{
    public :
        void move (int x0,int y0){
            coord.first+=x0;
            coord.second+=y0;
        } // Change la position, à utiliser surement avec des + ou -1 seulement pour éviter des téléportations
        pair<int,int> getpos(){
            return coord;
        }
        char getchar(){
            return e;
        }
        bool isalive(){
            return alive;
        }
        bool assezproche(person*,person*);
        int portee=1;
    private :
        std::pair <int,int> coord;
        char e; // char de représentation
    protected:
        person(int x0,int y0,int h0,char c0,int str0):coord(x0,y0),e(c0),h(h0),str(str0){}; //Constructeur private à accéder grace aux sous-classe !PAS DE PERSON H DANS LE CODE!
        int h; //points de vie
        bool alive= true;
        int str; //point de force
};

class enemy:public person{
    public:
    void hit(int d, Hero* H){
        if (h-d>0){
            h-=d; //réduit sa vie
        }
        else{
            die(H);
            alive=false;//meurt si il a plus de vie
        }
    }
    void attaque(Hero* H, vector< enemy* > L){
        for(int i=0;i<L.size();i++){
            if (assezproche(H,L[i]))
                H->hit(L[i]->str);
        }
    }
    
    void die(Hero* H){
        H->plusexp(expgiven);
    }
    private:
        int expgiven; //expérience donnée au joueur en mourant
    protected:
        enemy(int x0,int y0,int h0,char c0,int str0,int expgiven0):person(x0,y0,h0,c0,str0),expgiven(expgiven0){};
};

class bat:public enemy{
    public :
        bat(int x0,int y0):enemy(x0,y0,3,'~',1,20){
        };
};

class DK:public enemy{
    public :
        DK(int x0,int y0):enemy(x0,y0,30,'&',5,1000){
        };
};

class goblin:public enemy{
    public :
        goblin(int x0,int y0):enemy(x0,y0,6,'G',2,50){
        };
};

class skeleton:public enemy{
    public :
        skeleton(int x0,int y0):enemy(x0,y0,8,'S',3,100){
        };
};

class bme:public enemy{
    public :
        bme(int x0,int y0):enemy(x0,y0,2,'<',1,10){
        };
};

class Hero:public person{
    public :
        Hero(int x0,int y0):person(x0,y0,10,'@',2),mana(10),exp(0),level(1),intel(3),armor(1){
        };
        void plusexp(int plus){
            exp+=plus; // rajoute l'exp au personnage
            getlevel();
        }
        void getlevel(){
            while (exp < pow(level,2) ){
                level +=1;
                h+=5;
                hmax+=5;
                str+=2;
                intel+=2;
            }
        }
        void hit(int d){
            if (d<h){
                h-=max(0,d-armor);
            }
            else{
                alive=false;
            }
        }
        void attaque(Hero* H, vector< enemy* > L){
            for(int i=0;i<L.size();++i){
                if (assezproche(H,L[i]))
                    L[i]->hit(H->str,H);
            }
        }
        bool surobjet(Objet*);
        void powerup(vector<Objet* >O){
            for (int i=0;i<O.size();++i){
                if (surobjet(O[i])){
                    char c (O[i]->GetChar());
                    int val=O[i]->GetVal();
                    switch (c){
                        case '(': portee+=1;
                        case '$': gold+=val;
                        case 'p': h=min(hmax,h+val);
                        case 'P': h=min(hmax,h+val);
                        case 'c': armor+=val;
                        case 'M': armor+=val;
                        case '!': str+=val;
                    }
                }
            }
        }
    private:
        int mana; //point de magie nécéssaire pour prendre des dégats
        int level; // le niveau du personnage
        int intel; //point d'intelligence, comme les points de force mais pour la magie
        int gold; // argent
        int exp; //expérience du personnage(à augmenter pour gagner en niveau)  
        int armor; // armure du personnage
        int hmax=10;
};