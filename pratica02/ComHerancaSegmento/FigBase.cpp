#include<iostream>
using namespace std;

#include "FigBase.h"

FigBase::FigBase(double x, double y, int esp, int cor, int tipo){
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

void FigBase::le(double x, double y, int esp, int cor, int tipo){
    setX(x);
    setY(y);
    setEspessura(esp);
    setCor(cor);
    setTipo(tipo);
}

void FigBase::setX(double x){
    this->x = x;
}

void FigBase::setY(double y){
    this->y = y;
}

void FigBase::setEspessura(int esp){
    espessura = esp;
}

void FigBase::setCor(int cor){
    this->cor = cor;
}

void FigBase::setTipo(int tipo){
    this->tipo = tipo;
}

double FigBase::getX() const {
    return x;
}

double FigBase::getY() const {
    return y;
}

int FigBase::getEspessura() const {
    return espessura;
}

int FigBase::getCor() const {
    return cor;
}

int FigBase::getTipo() const {
    return tipo;
}

void FigBase::imprime() const {
    cout << " Atributos da linha:" << endl;
    cout << "   Espessura = " << espessura << endl;
    cout << "   Cor       = " << cor << endl;
    cout << "   Tipo      = " << tipo << endl;
    cout << " x = " << x << " y = " << y << endl;
}