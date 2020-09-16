#ifndef CIRCULO_H
#define CIRCULO_H

#include "FigBase.h"

class Circulo : public FigBase {
    public:
        Circulo(double, double, double, int, int, int);

        double getRaio() const;

        void setRaio(double);
        
        float area() const;
        float perimetro() const;
        void imprime() const;
    private:
        double raio;
};

#endif