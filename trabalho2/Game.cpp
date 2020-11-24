#include<iostream>
using namespace std;
#include "Game.h"


Game::Game(const int altura, const int largura, const int tamCobra){
    for(int i=0;i<10;i++) { // inicializando a Struct comida com 0
        Food[i].comida.first = 0;
        Food[i].comida.second = 0;
        Food[i].tempo = 0;
    }
    anaconda = new Snake(tamCobra);
    tela = new Screen(altura, largura);
    anaconda->draw(*tela, tela->SNAKE);
}

Game::~Game(){
    delete anaconda;
    delete tela;
}

/*Game::Game(const Game &other){
    *this = other; 
}*/

Game & Game::operator=(const Game &other){
    if(this==&other) return *this; // testa auto atribuição

    delete anaconda;
    delete tela;

    anaconda = other.anaconda;
    tela = other.tela;
    for(int i=0;i<10;i++) {
        Food[i].comida.first = other.Food[i].comida.first;
        Food[i].comida.second = other.Food[i].comida.second;
        Food[i].tempo = other.Food[i].tempo;
    }
    return *this;
}

/*const Screen& Game::getScreen() const { // retorna a tela atual do jogo
    return tela;
}*/


bool Game::step(int dr, int dc){ //deu pra cobra movimentar? return s: return n
    if( (anaconda->getLineHead() + dr == anaconda->getPrevLineHead() ) || (anaconda->getColHead() + dc == anaconda->getPrevColHead()) ){ // verificando se a snakeHead não está tentando fazer o caminho contrário
        return false;
    }
    for(int i=0;i<tela->getWidth();i++){
        if( (anaconda->getLineHead() + dr > tela->getHeightX(i)) || (anaconda->getLineHead() + dr < 0) || (anaconda->getColHead() + dc > tela->getWidth()) || (anaconda->getColHead(i+dc)  < 0) || getWidthX(i) + dc == 0 ){ //verificando se a snakeHead não está tentando colidir na parede
            return false;
        }
    }

    if(tela->get(anaconda->getLineHead()+dr,anaconda->getColHead()+dc)==Screen::SNAKE) // se a próxima posição for uma cobra
        return false;

    anaconda->draw(*tela, tela->EMPTY);

    for(int i=0;i<getNumFood();i++){ //Para todas as comidas disponíveis 
        if(anaconda->getLineHead()+dr ==  Food[i].comida.first && anaconda->getColHead()+dc == Food[i].comida.second && Food[i].tempo > 0){ // verifico se a próxima posição está no lugar da comida e se a comida está viva...
            if(anaconda->move(dr,dc,true)){ // se conseguir mexer enquanto está comendo
                anaconda->draw(*tela, tela->SNAKE);
                Food[i].tempo--; 
                return true;
            }
        }        
    }
    if(anaconda->move(dr,dc,false)){ // se conseguir mexer enquanto não estiver comendo
        anaconda->draw(*tela, Screen::SNAKE);
        for(int i=0;i<10;i++){
            if(Food[i].tempo > 0)
                Food[i].tempo--;
        }
        //cout << "nada pra comer" << endl;
        return true;
    }
}   

void Game::addFood(int r, int c, int ttl){ //ttl = time to live(quanto tempo a comida deve existir em termos de iterações)
    Food[getPosEmpty()].comida.first = r;
    Food[getPosEmpty()].comida.second = c;
    Food[getPosEmpty()].tempo = ttl;
    tela->set(r,c,tela->FOOD);
}

int Game::getPosEmpty() const { // retorna uma posição disponivel
    for(int i=0;i<10;i++){
        if(Food[i].tempo == 0)
            return i; //como todo o array de struct comida foi inicializado com 0, e todo o tempo recebe um valor que não é 0 então a primeira posição que tiver com 0 será retornada indicando uma posição disponível
    }
}

int Game::getNumFood() const{
    int cont = 0;
    for(int i=0;i<10;i++) {
        if(Food[i].tempo != 0)
            cont++; // para cada tempo diferente de 0 -> cont++ -> total de comidas presentes
    }
    return cont;
}