#ifndef SNAKE_H
#define SNAKE_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---


class Node;


class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public:
		Node(const int &elem): data(elem), next(NULL), prev(NULL) {} // forma de inicialização dos dados
		int data;
		Node *next; //aponta para o próximo nodo
		Node *prev; //aponta para o nodo anterior
};

class Snake {
    public:
        Snake(const int)
        Snake(const Snake &);
        ~Snake();
        void draw(const Screen& s,int state); //desenha a cobra no objeto da classe Screen s, state tamanho da cobra
        void move(int dr, int dc, bool eating); // move a cabeça da cobra na direção dr, dc; eating indica se a cobra esta comendo ou não
        int getLenght(); //retorna o tamanho da cobra em pixels

        // --- Novas Funções --- //
        void push_back(const int elem);

    private:
        Node pair<int,int> *dataFirst, * dataLast;
        const Screen& scr;
        //adicionar outros possíveis membros de dados privado e mais funções de uma lista duplamente encadeada
}

#endif