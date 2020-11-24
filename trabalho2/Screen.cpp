#include<iostream>
using namespace std;
#include "Screen.h"

Screen::Screen(int altura_, int largura_) : altura(altura_), largura(largura_){
    dataHeight = new int[largura](); //inicializa o vetor com 0

    // cria por padrão uma matriz dinâmica
    data = new int*[largura];
    for(int i=0;i<largura;i++)
        data[i] = new int[dataHeight[i]];
}

// destrutor
Screen::~Screen(){
    for(int i=0;i<largura;i++)
        delete[] data[i];
    delete[] data;
    delete[] dataHeight;
}

// construtor de cópia
/*Screen::Screen(const Screen &other){
	*this = other; 
}*/

// operador de atribuição
Screen & Screen::operator=(const Screen &other){
    if(this==&other) return *this; 
	
    for(int i=0;i<largura;i++)
        delete[] data[i];
    delete[] data;
    delete[] dataHeight;

    dataHeight = new int[other.largura];
    for(int i=0;i<other.largura;i++)
        dataHeight[i] = other.dataHeight[i];

    data = new int*[other.largura];
    for(int i=0;i<other.largura;i++)
        data[i] = new int[dataHeight[i]];
    
    for(int i=0;i<largura;i++)
        for(int j=0;j<dataHeight[i];j++){
            data[i][j] = other.data[i][j];
        }
    altura = other.altura;
    largura = other.largura;
	return *this;
}

const int Screen::get(const int r, const int c) const{ // estado do pixel nesta posição
    if((r<0 || c<0) || (r>=altura || c>=largura)) // se estiver fora da matriz quadrada 
        return WALL; 
    else if(r>=dataHeight[c] || dataHeight[c] == 0) // se estiver dentro da matriz quadrada mas fora da matriz dinâmica 
        return EMPTY;
    else // caso contrário o pixel é valido, retorna o que estiver na matriz dinâmica
        return data[c][r];
}

void Screen::set(const int r,const int c, const int val){
    
    if(r<dataHeight[c]-1){
        data[c][r] = val;
       // cout << "linha é menor ou igual que a linha atual" << endl;
    }
    else{
        //cout << "linha é maior que a linha atual" << endl;
        // coluna para auxiliar o redimensionamento
        int *colunaAux = new int[r+1];
        
        // guarda o valor antigo da coluna
        for(int i=0;i<dataHeight[c];i++){
            colunaAux[i] = data[c][i];
        }

        // destroi a coluna para novos valores
        delete[] data[c];
    
        // constrói com novos valores
        data[c] = new int[r+1];
        for(int i=0;i<dataHeight[c];i++){
            data[c][i] = colunaAux[i];
        }

         // atualiza dataHeight
        dataHeight[c] = r+1;

        // destroi auxiliar
        delete[] colunaAux;

        // da o valor para o pixel
        data[c][r] = val;
    }
} 