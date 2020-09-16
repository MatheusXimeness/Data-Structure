#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "FigBase.h"
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;

class Segmento : public FigBase {

    

    public:
        Segmento(double, double, double, double, int, int, int);
        Segmento();
        double getX2() const;
        double getY2() const;

        void setX2(double);
        void setY2(double);

        float area() const;
        float perimetro() const;
        void le();
        void imprime() const;

        friend ostream & operator<<(ostream&, const Segmento&);
        friend istream & operator>>(istream&, Segmento&);
    private:
        double x2, y2;
};

#endif
