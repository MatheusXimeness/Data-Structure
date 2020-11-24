#ifndef SCREEN_H
#define SCREEN_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---

class Screen {
    public:
        static const int EMPTY = 0; // constante do pixel vazio
        static const int SNAKE = 1; // constante do pixel da cobra
        static const int FOOD  = 2; // constante do pixel da comida
        static const int WALL  = 3; // constante do pixel da parede

        Screen(int altura_, int largura_); // construtor padrão
        //Screen(const Screen &other); // constrtuor por cópia 
        Screen & operator=(const Screen &); // operador de atribuição 
        ~Screen(); // destrutor

        const int getWidth() const{ return largura; }// retorna altura
        const int getHeight() const{ return altura; } // retorna largura
        const int get(const int r, const int c) const; // retorna o estado do pixel nesta posição
        
        void set(const int r, const int c, const int val); // seta valores para os pixels

        int getHeightX(int i) const { return dataHeight[i]; }
        int getWidhtX(int i) const { return dataHeight[i]; }

    private:
        int **data, *dataHeight; // dataHeight = array de alturas 
        int largura, altura; // em termos de números de pixel (??)
};

#endif