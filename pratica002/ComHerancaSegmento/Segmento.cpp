#include "Segmento.h"
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

Segmento::Segmento(double x, double y, double x2, double y2, int esp, int cor, int tipo):
                    FigBase(x,y,esp,cor,tipo) {
    setX2(x2);
    setY2(y2);
}

Segmento::Segmento() : FigBase(1,1,1,1,1){
    setX2(1);
    setY2(1);
}


void Segmento::setX2(double x2) {
    this->x2 = x2;
}

void Segmento::setY2(double y2) {
    this->y2 = y2;
}

double Segmento::getY2() const {
    return y2;
}

float Segmento::area() const {
    return 0;
}

float Segmento::perimetro() const {
    return (sqrt(pow((x2-FigBase::getX()),2)+pow((y2-FigBase::getY()),2)));
}

void Segmento::imprime() const {
    cout << "--- [Segmento] ---" << endl;
    FigBase::imprime();
    cout << " x2 = " << x2 << " y2 = " << y2 << endl;
    cout << " area = " << area() << " perimetro = " << perimetro() << endl;
}

void Segmento::le(){
    double x, y, x2, y2;
    int espessura, cor, tipo;

    cin >> x >> y >> x2 >> y2;
    cin >> espessura >> cor >> tipo;

    setX2(x2);
    setY2(y2);
    FigBase::le(x, y, espessura, cor, tipo);
}

istream & operator>>(istream& cout, Segmento& seg){
    seg.le();
    return cout;
}

ostream & operator<<(ostream& cin, const Segmento& seg){
    seg.imprime();
    return cin;
}
