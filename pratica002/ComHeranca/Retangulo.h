#ifndef RETANGULO_H
#define RETANGULO_H

#include "FigBase.h"

class Retangulo : public FigBase {
    public:
        Retangulo(double, double, double, double, int, int, int);

        double getLargura() const;
        double getAltura() const;

        void setLargura(double);
        void setAltura(double);

        float area() const;
        float perimetro() const;
        void imprime() const;
    private:
        double largura, altura;
};

#endif