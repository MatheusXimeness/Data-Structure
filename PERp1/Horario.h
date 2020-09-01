#ifndef HORARIO_H
#define HORARIO_H
#include <iostream>
using namespace std;

class Horario {
    public:
        Horario(int, int, int);
        Horario(const Horario&);

        void setHora(int);
        void setMinuto(int);
        void setSegundo(int);
        
        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        int compHorario(const Horario&);
        int difSegundos(const Horario&);
        void imprime();

    private:
        int hora;
        int minuto;
        int segundo;

};

#endif