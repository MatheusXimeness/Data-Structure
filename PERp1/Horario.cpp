#include <iostream>
using namespace std;

#include "Horario.h"

Horario::Horario(int h, int m, int s){
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

Horario::Horario(const Horario& hr){
    hora = hr.hora;
    minuto = hr.minuto;
    segundo = hr.segundo;
}

void Horario::setHora(int h){
    if(h>=0 && h<=23)
        hora = h;
    else if(h<0)
        hora = 0;
    else if(h>23)
        hora = 23;
}

void Horario::setMinuto(int m){
    if(m>=0 && m<=60)
        minuto = m;
    else if(m<0)
        minuto = 0;
    else if(m>60)
        minuto = 60;
}

void Horario::setSegundo(int s){
    if(s>=0 && s<=60)
        segundo = s;
    else if(s<0)
        segundo = 0;
    else if(s>60)
        segundo = 60;
}

int Horario::getHora() const{
    return hora;
}

int Horario::getMinuto() const{
    return minuto;
}

int Horario::getSegundo() const{
    return segundo;
}

int Horario::compHorario(const Horario& hr){
    if(difSegundos(hr) > 0)
        return -1;
    else if(difSegundos(hr) < 0)
        return 1;
    else 
        return 0;
}

int Horario::difSegundos(const Horario& hr){
    int difSegundos = (hr.hora*3600 + hr.minuto*60 + hr.segundo) - (hora*3600 + minuto*60 + segundo);
    return difSegundos;
}


void Horario::imprime() {
    cout << hora << ":" << minuto << ":" << segundo;
}