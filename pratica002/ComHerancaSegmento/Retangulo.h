#ifndef RETANGULO_H
#define RETANGULO_H

#include "FigBase.h"
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;


class Retangulo : public FigBase {


    public:
        Retangulo(double, double, double, double, int, int, int);
        // DUVIDA Retangulo(double = 0.0, double = 0.0, double = 0.0, double = 0.0, int = 1, int = 1, int =1);
        double getLargura() const;
        double getAltura() const;

        void setLargura(double);
        void setAltura(double);

        float area() const;
        float perimetro() const;

        void le();
        void imprime() const;

        friend ostream & operator<<(ostream&, const Retangulo&);
        friend istream & operator>>(istream&, Retangulo&);

    private:
        double largura, altura;
};

#endif