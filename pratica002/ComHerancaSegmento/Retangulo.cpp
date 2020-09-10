#include "Retangulo.h"
using std::cin;
using std::cout;
using std::endl;


Retangulo::Retangulo(double x, double y, double alt, double larg, int esp, 
                     int cor, int tipo) : FigBase(x, y, esp, cor, tipo) {
    setAltura(alt);
    setLargura(larg);                         
}

Retangulo::Retangulo(): FigBase(1,1,1,1,1){
    setAltura(1);
    setLargura(1);
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

void Retangulo::le(){
    double x, y, altura, largura;
    int espessura, cor, tipo;

    cin >> x >> y >> altura >> largura;
    cin >> espessura >> cor >> tipo;

    setAltura(altura);
    setLargura(largura);
    FigBase::le(x, y, espessura, cor, tipo);
}


ostream & operator<<(ostream& cout, const Retangulo& re){
    re.imprime();
    return cout;
}

istream & operator>>(istream& cin, Retangulo& re){
    re.le();
    return cin;
}

