class person{
    public :
        void move (int x0,int y0){
            x+=x0;
            y+=y0;
        } // Change la position, à utiliser surement avec des + ou -1 seulement pour éviter des téléportations
        void hit(int d){
            if (h-d>0){
                h-=d; //baisse les points de vie
            }
            else{
                die(); // meurt
            }
        }
        void attack(person* H){
            H->hit(str); //la personne attaquée prend des dégats
        }
        void die(){

        };
    private :
        int x;
        int y;
        int h; //points de vie
        char e; // char de représentation
        int str; //point de force
    protected:
        person(int x0,int y0,int h0,char c0,int str0):x(x0),y(y0),h(h0),str(str0){}; //Constructeur private à accéder grace aux sous-classe !PAS DE PERSON H DANS LE CODE!
};

class bat:public person{
    public :
        bat(int x0,int y0):person(x0,y0,3,'~',1){
        };
};

class DK:public person{
    public :
        DK(int x0,int y0):person(x0,y0,30,'#',5){
        };
};

class goblin:public person{
    public :
        goblin(int x0,int y0):person(x0,y0,6,'ù',2){
        };
};

class skeleton:public person{
    public :
        skeleton(int x0,int y0):person(x0,y0,8,'$',3){
        };
};

class bme:public person{
    public :
        bme(int x0,int y0):person(x0,y0,2,'ç',1){
        };
};

class Hero:public person{

    public :
        Hero(int x0,int y0):person(x0,y0,10,'@',2),mana(10),exp(0),level(1),intel(3){
        };
        int exp; //expérience du personnage(à augmenter pour gagner en niveau)

    private:
        int mana; //point de magie nécéssaire pour prendre des dégats
        int level; // le niveau du personnage
        int intel; //point d'intelligence, comme les points de force mais pour la magie
    
};