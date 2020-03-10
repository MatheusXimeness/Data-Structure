#include<iostream>
#include"FigBase.h"
#include "Circulo.h"
using namespace std;


Circulo::Circulo(double x, double y, double raio, int espessura, int cor, int tipo) 
                : FigBase(x,y,espessura,cor,tipo){
    setRaio(raio);
}

void Circulo::imprime(){
    cout << "--- [Circulo] ---" << endl;
    FigBase::imprime();
    cout << "raio = " << getRaio() << endl;
    cout << "area = " << area() << " perimetro = " << perimetro() << endl;
    cout << endl;
}

void Circulo::setRaio(double raio){
    this->raio = raio;
}

double Circulo::getRaio() const {
    return raio;
}

float Circulo::perimetro() {
    float perimetro = 2*3.14*raio; 
    return perimetro;
}

float Circulo::area() {
    float area = (raio*raio)*3.14;
    return area;
}

