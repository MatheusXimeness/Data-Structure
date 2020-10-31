#ifndef SNAKE_H
#define SNAKE_H
// para debugs, tirar depois
    #include<iostream>
    #include<istream>
    #include<ostream>
    using namespace std;
// ---

template<class T>
class Node;

template<class T>
class Node { //a classe Node sera "escondida" quando trabalharmos com iteradores
	public:
		Node(const T&elem): data(elem), next(NULL), prev(NULL) {} // forma de inicialização dos dados
		T data;
		Node<T> *next; //aponta para o próximo nodo
		Node<T> *prev; //aponta para o nodo anterior
};

class Snake {
    public:
        Snake(int)
        Snake(const Snake &);
        ~Snake();
        void draw(Screen s,int state); //desenha a cobra no objeto da classe Screen s, state tamanho da cobra
        void move(int dr, int dc, bool eating); // move a cabeça da cobra na direção dr, dc; eating indica se a cobra esta comendo ou não
        int getLenght(); //retorna o tamanho da cobra em pixels

    private:
        Node<T> *dataFirst, * dataLast;
        //adicionar outros possíveis membros de dados privado e mais funções de uma lista duplamente encadeada
}

#endif