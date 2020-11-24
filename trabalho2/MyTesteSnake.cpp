#include "Snake.h"
#include "Screen.h"
#include <iostream>

using namespace std;

void print(const Screen &s) {
    for (int j = 0; j < s.getWidth() + 2; j++) cout << "-";
    cout << endl;
    for (int i = 0; i < s.getHeight(); i++) {
        cout << "|";
        for (int j = 0; j < s.getWidth(); j++) {
            if (s.get(s.getHeight() - 1 - i, j) == Screen::EMPTY) cout << " ";
            else if (s.get(s.getHeight() - 1 - i, j) == Screen::SNAKE) cout << "#";
            else cout << "$";
        }
        cout << "|" << "\n";
    }
    for (int j = 0; j < s.getWidth() + 2; j++) cout << "-";
    cout << "\n\n";
}

int main() {
    int height = 6, width = 10;
    Screen screen(height, width);
    print(screen);

    Snake snake(4);
   
    snake.draw(screen,Screen::SNAKE);
   
    print(screen);
    snake.draw(screen,Screen::EMPTY);
    snake.move(0,1,false);
    snake.draw(screen,Screen::SNAKE);
    print(screen);
    cout<<snake.getLength()<<endl;
    return 0;
}