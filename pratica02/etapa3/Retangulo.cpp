#include<iostream>
#include"FigBase.h"
#include"Retangulo.h"
using namespace std;

Retangulo::Retangulo(double x, double y, double largura, double altura, int espessura, int cor, int tipo) 
            : FigBase(x, y, espessura, cor, tipo){
    setLargura(largura);
    setAltura(altura);
}

double Retangulo::getLargura() const{
    return largura;
}

double Retangulo::getAltura() const{
    return altura;
}

void Retangulo::setLargura(double largura){
    this->largura = largura;
}
void Retangulo::setAltura(double altura){
    this->altura = altura;
}

float Retangulo::area(){
    float area = largura*altura;
    return area;
}
float Retangulo::perimetro(){
    float perimetro = (2*largura) + (2*altura);
    return perimetro;
}

void Retangulo::imprime(){
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << "largura = " << getLargura() << " altura = " << getAltura() << endl;
    cout << "area = " << area() << " perimetro = " << perimetro() << endl;
    cout << endl;
}