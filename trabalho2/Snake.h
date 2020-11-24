#ifndef SNAKE_H
#define SNAKE_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---
#include "Screen.h"

class Node;


class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public:
		Node(const int dr, const int dc): data(dr, dc), next(NULL), prev(NULL) {} // forma de inicialização dos dados
		pair<int, int> data;
		Node *next; //aponta para o próximo nodo
		Node *prev; //aponta para o nodo anterior
};

class Snake {
    public:
        Snake(const int); // construtor padrão
        //Snake(const Snake &); // construtor por cópia 
	    Snake & operator=(const Snake &); // operador de atribuição
        ~Snake(); // destrutor

        void draw(Screen& s,int state); //desenha a cobra no objeto da classe Screen s, state tamanho da cobra
        bool move(int dr, int dc, bool eating); // move a cabeça da cobra na direção dr, dc; eating indica se a cobra esta comendo ou não
        int getLength() const; //retorna o tamanho da cobra em pixels

        // --- Novas Funções --- //
        void push_back(const int dr, const int dc); // adiciona um pixel à cobra
        
        int getLineHead() const { return dataLast->data.first; } // retorna a linha da cabeça da cobra
        int getColHead() const { return dataLast->data.second; } // retorna a coluna da cabeça da cobra

        int getPrevLineHead() const { return dataLast->data.second; } // retorna a linha de uma posição antes da cabeça da cobra
        int getPrevColHead() const { return dataLast->data.second; } // retorna a coluna de uma posição antes da cabeça da cobra
        
        int getLineTail() const { return dataFirst->data.first; } // retorna a linha da cauda da cobra
        int getColTail() const { return dataFirst->data.second; } // retorna a coluna da cauda da cobra
    private:
        void destroy( Node *minhaCobra );

        Node  *dataFirst, *dataLast; 
};

#endif