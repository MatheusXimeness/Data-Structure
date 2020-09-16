#include "Retangulo.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

Retangulo::Retangulo(double x, double y, double largura, double altura,
                     int e, int c, int t) : FigBase(x, y, e, c, t) {
    setLargura(largura);
    setAltura(altura);
}

double Retangulo::getLargura() const {
    return largura;
}

void Retangulo::setLargura(double larg) {
    largura = larg;
}

double Retangulo::getAltura() const {
    return altura;
}

void Retangulo::setAltura(double alt) {
    altura = alt;
}

float Retangulo::area() const {
    return altura * largura;
}

float Retangulo::perimetro() const {
    return 2*(largura + altura);
}

void Retangulo::imprime() const {
    cout << "--- [Retangulo] ---" << endl;
    FigBase::imprime();
    cout << " largura=" << getLargura() << " altura=" << getAltura() << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}

ostream& operator<< (ostream &out, const Retangulo &r) {
    r.imprime();
   return cout;
}

istream& operator>> (istream &cin, Retangulo &r) {
    r.ler();
    return cin;
}

void Retangulo::ler(){
    FigBase::ler();
    double largura, altura;

    cout << "altura = ";
    cin >> altura; setAltura(altura);
    cout << "largura = ";
    cin >> largura; setLargura(largura);
} 
