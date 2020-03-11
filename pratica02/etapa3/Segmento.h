#ifndef SEGMENTO_H
#define SEGMENTO_H
#include"FigBase.h"

class Segmento : public FigBase{
    public:
        Segmento(double, double, double, double, int, int, int);

        double getX2() const;
        double getY2() const;

        void setX2(double);
        void setY2(double);

        float area() const;
        float perimetro() const;
        void imprime() const;
    private:
        double x2, y2;
};


#endif