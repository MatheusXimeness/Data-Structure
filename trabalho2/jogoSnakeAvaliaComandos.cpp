#include <iostream>
#include <string>
#include <sstream>
#include "Game.h"

using namespace std;

//ATENCAO
//ATENCAO
//ATENCAO
//ATENCAO
//Nao considere este programa como um exemplo de boa implementacao!
//Por exemplo, ha partes deles que foram desenvolvidas propositalmente de forma "nao muito correta" com o objetivo de fazer com que
//implementacoes nao 100% corretas da classe Game compilem e executem corretamente
//Tais implementacoes "nao 100% corretas" provavelmente falharao em outros casos de teste usados no Submitty
//ATENCAO
//ATENCAO
//ATENCAO
//ATENCAO


void print(const Screen &s) {
	for(int j=0;j<s.getWidth()+2;j++) cout << "-"; 
	cout << endl;
	for(int i=0;i<s.getHeight();i++) {
		cout << "|";
		for(int j=0;j<s.getWidth();j++) {
			if(s.get(s.getHeight()-1-i,j)==Screen::EMPTY) cout << " ";
			else if(s.get(s.getHeight()-1-i,j)==Screen::SNAKE) cout << "#";
			else cout << "$";
		}
		cout << "|" << "\n";
	}
	for(int j=0;j<s.getWidth()+2;j++) cout << "-"; 
	cout << "\n\n";
}

int main() {
	string st;
	int h,w,snakeLen;
	cin >> h >> w >> snakeLen;
	Game game(h,w,snakeLen); 

	print(game.getScreen());
	string command;
	while(cin >> command) {		
		if(command=="step") {
			int dr,dc;
			cin  >> dr >> dc;
			bool ok = game.step(dr,dc);
			if(!ok) {
				print(game.getScreen());
				return 0;
			}
		} else if (command=="food") {
			int r,c, ttl;
			cin  >> r >> c >> ttl;
			game.addFood(r,c,ttl);
		}
		print(game.getScreen());
	}
	return 0;
}
