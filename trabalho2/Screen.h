#ifndef SCREEN_H
#define SCREEN_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---

//Matriz dinamica semelhante a matriz tradicional do ultimo trabalho
class Screen {
    public:
        const int FOOD, SNAKE, EMPTY, WALL;
        Screen(int altura_, int largura_) : altura(altura_), largura(largura_);
        int getWidth(); // retorna altura
        int getHeight(); // retorna largura
        get(int r, int c); // estado do pixel nesta posição
        void set(int r, int c, const int val); 
    private:
        int *data, *dataHeight;
        int largura, altura; // em termos de números de pixel (??)
}

#endif