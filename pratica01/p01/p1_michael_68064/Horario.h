/*
    Aluno: Michael Canesche - 68064
*/

#ifndef HORARIO_H
#define HORARIO_H

#include <iostream>
using namespace std;

class Horario{
    
    private:
        int hora, minuto, segundo;
    public:
        Horario(int h = 0, int m = 0, int s = 0);
        Horario(const Horario &hr);
        void imprime();
        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;
        int compHorario(Horario hms);
        int difSegundos(Horario hms);

};

istream& operator>>(istream &is, Horario &h);
ostream& operator<<(ostream &os, Horario h);

#endif
