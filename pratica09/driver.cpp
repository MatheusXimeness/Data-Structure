#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
#include "MyStack.h"
#include "MyQueue.h"


void etapa1() {
	MyStack<int> stack;
	MyQueue<int> queue;
	int elm;

	for(int i = 0; i < 6; i++){
		cin>>elm;
		queue.push(elm);
		stack.push(elm);
	}
	
	while(!stack.empty()){
		cout << stack.top() << " ";
		stack.pop();
	}
	cout << endl;

	while(!queue.empty()){
		cout << queue.front() << " ";
		queue.pop();
	}
	cout << endl;	
	
}

// Para a pilha os ultimos elementos a serem inseridos são os primeiros a serem impressos, enquanto para fila os primeiros a serem impressos 
// são os primeiros elementos inseridos.

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> stack;
	char cons;
	while(cin>>cons){
		if(stack.empty() && (cons == ')' || cons == ']' || cons == '}')){
			stack.push(cons);
			break;
		}
		if((cons == '(') || (cons == '[') || (cons == '{'))
			stack.push(cons);
		if((stack.top() == '(') && (cons == ')'))
			stack.pop();
		else if((stack.top() == '[') && (cons == ']'))
			stack.pop();
		else if((stack.top() == '{') && (cons == '}'))
			stack.pop();
	}
	if(stack.empty())
		cout<<"Consistente" << endl;
	else
		cout<<"Inconsistente" << endl;
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...


#include "MyQueue2.h"
void etapa3() {
	char operacao;
	MyQueue2<string> q;

	//le um arquivo contendo "comandos" para a fila e aplica-os a fila criada com sua classe...
	while(cin>> operacao) {
		if(operacao=='p') {
			string st;
			cin >> st;
			q.push(st); //insere um novo elemento na sua fila...
		} else if(operacao=='f') {
			cout << q.front() << "\n";
		} else if(operacao=='P') {
			q.pop();
		} else if(operacao=='e') {
			cout << ((q.empty())?"vazia":"cheia") << "\n";
		} else cout << q.size() << "\n";
	}	
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....


void etapa4() {
	int n, elm, cont;
	cont = 1;
	cin >> n;
	MyStack<int> stack;
	for (int i = 0; i < n; i++){
		cin>> elm;
		if(stack.empty() || elm > stack.top() ){
			for(int j = cont; j <= elm; j++){
				stack.push(j);
				cont++;
			}
			stack.pop();	
		} else if(elm == stack.top()){
				stack.pop();
		} else
			break;
	}
	if(stack.empty())
		cout<< "SIM" << endl;
	else
		cout << "NAO" << endl; 
	
}

//---------------------------------------


int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
		case 4:
			cout << "Etapa 4" << endl;
			etapa4();
			break;
	}
}