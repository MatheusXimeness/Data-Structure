#include<iostream>
#include "Segmento.h"
using namespace std;

Segmento::Segmento(double x, double y, double x2, double y2, int espessura, int cor, int tipo)
        : FigBase(x, y, espessura, cor, tipo){
    setX2(x2); setY2(y2);
}

void Segmento::imprime() const{
    cout << "--- [Segmento] ---" << endl;
    FigBase::imprime();
    cout << "x2 = " << getX2() << " y2 = " << getY2() << endl;
    cout << "area = " << area() << " perimetro = " << perimetro() << endl;
    cout << endl; 
}

void Segmento::setX2(double x2) {
    this->x2 = x2;
}

void Segmento::setY2(double y2) {
    this->y2 = y2;
}

double Segmento::getX2() const {
    return x2;
}

double Segmento::getY2() const {
    return y2;
}

float Segmento::area() const {
    return 0;
}

float Segmento::perimetro() const {
    return (x2 + y2 + FigBase::getX() + FigBase::getY());
}