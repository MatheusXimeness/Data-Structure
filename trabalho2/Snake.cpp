#include<iostream>
using namespace std;
#include "Snake.h"

Snake::Snake(const int initialSize){
    for(int i=0;i<initialSize;i++)
        push_back(0); // não sei se a função pushback está correta
}
Snake::Snake(const Snake &){

}
Snake::~Snake(){

}
void Snake::draw(const Screen& s,int state){ //desenha a cobra no objeto da classe Screen s, state tamanho da cobra
}

void Snake::move(int dr, int dc, bool eating){

} 

// ------ Novas Funções ------- //
void Snake::push_back(const int elem) {
	if(dataFirst==NULL) { //caso especial: lista inicialmente vazia
		dataFirst = dataLast = new Node(elem);
	} else {
		dataLast->next = new Node(elem);
		dataLast->next->prev = dataLast;
		dataLast = dataLast->next;
	}
}