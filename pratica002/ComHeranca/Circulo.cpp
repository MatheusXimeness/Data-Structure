#include<iostream>
using namespace std;

#include "Circulo.h"

Circulo::Circulo(double x, double y, double r, int esp, int cor, int tipo):
                 FigBase(x, y, esp, cor, tipo) {
    setRaio(r);
}

double Circulo::getRaio() const {
    return raio;
}

void Circulo::setRaio(double r) {
    raio = r;
}

float Circulo::area() const {
    return (raio*raio)*3.14;
}

float Circulo::perimetro() const {
    return 2*3.14*raio;
}

void Circulo::imprime() const {
    cout << "--- [Circulo] ---" << endl;
    FigBase::imprime();
    cout << " raio = " << raio << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}