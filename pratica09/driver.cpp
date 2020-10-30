#include <iostream>

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"
#include "MyStack.h"
#include "MyQueue.h"


void etapa1() {
	int n = 6;
	MyStack<int> pilha;
	MyQueue<int> fila;
	for(int i=0;i<n;i++){
		int value; cin >> value;
		pilha.push(value);
		fila.push(value);
	}

	while(!pilha.empty()){
		cout << pilha.top() << " ";
		pilha.pop();
	}
	cout << '\n';

	while(!fila.empty()){
		cout << fila.front() << " ";
		fila.pop();
	}
	cout << '\n';
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> pilha;
	char symbol;
	while(cin>>symbol){
		if(symbol=='(' || symbol=='[' || symbol=='{')
			pilha.push(symbol);
			
		if(pilha.empty() && (symbol==')' || symbol==']' || symbol=='}')){
			cout << "Inconsistente\n"; return;
		}

		if(symbol==')' && pilha.top()=='(')
			pilha.pop();
		else if(symbol==']' && pilha.top()=='[')
			pilha.pop();
		else if(symbol=='}' && pilha.top()=='{')
			pilha.pop();
		
		
	}
	if(pilha.empty())
		cout << "Consistente\n";
	else
		cout << "Inconsistente\n";
}

//---------------------------------------

// Na etapa 3 voce deve implementar MyQueue2.h e descomentar os codigos de teste abaixo...


//#include "MyQueue2.h"
#include "MyPriorityQueue.h"
void etapa3() {
	MyPriorityQueue<int> fila;
	int n; cin >> n;
	while(cin>>n){
		fila.push(n);
	}
		fila.push(n);
	fila.print();
	/*char operacao;
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
	}	*/
}

//---------------------------------------

// Insira aqui o codigo para a etapa 4....

#include "MyPriorityQueue.h"
void etapa4() {
	
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