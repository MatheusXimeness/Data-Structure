#include<iostream>
using namespace std;
#include "Snake.h"

Snake::Snake(const int initialSize){
	dataFirst = dataLast = new Node(0, 0);
	for(int i=1;i<initialSize;i++){
		this->dataLast->next = new Node(0,i);
		this->dataLast->next->prev = this->dataLast;
		this->dataLast = this->dataLast->next;
	}
}

void Snake::draw(Screen& s,int state){ //desenha a cobra no objeto da classe Screen s, state tamanho da cobra
    Node * aux = this->dataFirst;
    for(int i=0;i<=getLength();i++){ //percorre a cobra toda
        s.set(aux->data.first,aux->data.second,state); // passa o par ordenado das posições da cobra
        aux = aux->next; // vai para o próximo nodo;
    }
}

bool Snake::move(int dr, int dc, bool eating){
    if(eating){ // se estiver comendo (pushBack)
        push_back(dr,dc);
    }else{ // se não estiver comendo
        push_back(dr,dc);
		if(getLength()>1){
			dataFirst = dataFirst->next; // atualiza a cauda
			delete dataFirst->prev;
		}
    }
	return true;
}

// Descobre o tamanho da cobra indo do dataFirst até o dataLast
int Snake::getLength() const{
    Node *aux = dataFirst;
    int cont = 0;
    while(aux!=dataLast){ 
        aux = aux->next;
        cont++;
    }
    return cont;
 }
    
// ------ Novas Funções ------- //

// destrutor
Snake::~Snake(){
	destroy(dataFirst);
} 

// Função auxiliar do destrutor e do operador de atribuição
void Snake::destroy( Node *minhaCobra ) {
	if(minhaCobra==NULL) return; //lista vazia
	destroy(minhaCobra->next);
	delete minhaCobra;
}
/*
// construtor por cópia
Snake::Snake(const Snake &other) {
	dataFirst = dataLast  = NULL; 
	*this = other; 
}*/



// Operador de atribuição
Snake & Snake::operator=(const Snake &other) {
	if(this==&other) return *this; 
	
	// preciso destruir a cobra aqui
	destroy(dataFirst);

    dataFirst = dataLast = NULL; //create

	if(other.dataFirst == NULL) { // caso especial
		dataFirst = dataLast = NULL;
	} else {
		Node *curr = other.dataFirst;
		while(curr!=NULL) { //equivalente a "while(curr)"
			push_back(curr->data.first, curr->data.second);
			curr = curr->next; //avance para o proximo nodo
		}
	}
	return *this;
}

void Snake::push_back(const int dr, const int dc) { // essa função pode receber apenas valores que irão movimentar a snakeHead
	Node *newNode = new Node(dataLast->data.first+dr,dataLast->data.second+dc); 
	dataLast->next = newNode;
	dataLast->next->prev = dataLast;
	dataLast = dataLast->next;
}