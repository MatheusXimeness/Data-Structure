#ifndef CIRCULO_
#define CIRCULO_
#include<iostream>
#include "FigBase.h"
using namespace std;

class Circulo : public FigBase {
    public:
        Circulo(double, double, double, int, int, int);

        double getRaio() const;
        
        void setRaio(double);
        
        float area();
        float perimetro();
        void imprime();
    private:
        double raio;
};

#endif