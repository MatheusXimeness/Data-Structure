#include<iostream>
using namespace std;
#include "Snake.h"

Screen(int altura_, int largura_) : altura(altura_), largura(largura_){
    dataHeight = new int[largura];
    for(int i=0;i<largura;i++)
        data = new int[1];
}
int getWidth(); // retorna altura
int getHeight(); // retorna largura
get(int r, int c); // estado do pixel nesta posição
void set(int r, int c, const int val); 