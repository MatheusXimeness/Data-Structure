#ifndef CIRCULO_H
#define CIRCULO_H

#include "FigBase.h"
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;


class Circulo : public FigBase {
    public:
        Circulo(double, double, double, int, int, int);
        Circulo();
        double getRaio() const;

        void setRaio(double);
        
        float area() const;
        float perimetro() const;
        
        void le();
        void imprime() const;

        friend ostream & operator<<(ostream&, const Circulo &);
        friend istream & operator>>(istream&, Circulo&);

    private:
        double raio;
};

#endif