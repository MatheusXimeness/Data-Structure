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

class Game {
    public:
        Game(int Altura, int Largura, int tamCobra);
        Game(const Game &);
        ~Game();
        Screen getScreen(); // retorna a tela atual do jogo
        bool step(int dr, int dc); //deus pra cobra movimentar? return s, return n
        addFood(int r, int c, int ttl); //ttl = time to live(quanto tempo a comida deve existir em termos de iterações)
        int getNumFood() const;
    private:
        Snake cobra;
        Screen tela;
        int *comidasOn; //nunca vai ter mais de 10 comidas ao mesmo tempo
        //outros membros de dados serão adicionados conforme necessário
}

#endif