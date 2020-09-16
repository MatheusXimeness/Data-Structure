#include<iostream>
using namespace std;

#include "Retangulo.h"

Retangulo::Retangulo(double x, double y, double alt, double larg, int esp, 
                     int cor, int tipo) : FigBase(x, y, esp, cor, tipo) {
    setAltura(alt);
    setLargura(larg);                         
}

double Retangulo::getAltura() const {
    return altura;
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}

float Retangulo::area() const {
    return largura*altura;
}

float Retangulo::perimetro() const {
    return (largura*2)+(altura*2);
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << " largura = " << largura << " altura = " << altura << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}
