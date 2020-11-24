#ifndef GAME_H
#define GAME_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---
//incluindo .h das classes que serão utilizadas para compor o game
#include "Snake.h"
#include "Screen.h"

// struct Comida tem como membros de dados um de pair<int,int> para localizar a comida na matriz
// tem também um int tempo para saber por quantas iterações ela ficará na tela 
struct Comida {
    pair<int,int> comida;
    int tempo;
};


class Game {
    public:
        Game(const int altura, const int largura, const int tamCobra);
        ~Game();
        //Game(const Game &);
        Game & operator=(const Game &other);

        const Screen getScreen() const { return *tela; } // retorna a tela atual do jogo
        int getNumFood() const;
        int getPosEmpty() const; //retorna uma posição disponivel
            
        bool step(int dr, int dc); //deu pra cobra movimentar? return s, return n
        void addFood(int r, int c, int ttl); //ttl = time to live(quanto tempo a comida deve existir em termos de iterações)
        
    private:
        Snake *anaconda;
        Screen *tela;
        Comida Food[10];
        //outros membros de dados serão adicionados conforme necessário
};

#endif