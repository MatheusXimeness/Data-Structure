#include<iostream>
using namespace std;

include "Horario.h"


Horario::Horario(int h, int m, int s){
    setHora(int h);
    setMinuto(int m);
    setSegundo(int s);
}

Horario::Horario(const Horario& h){
    hora = h.hora;
    minuto = h.minuto;
    segundo = h.segundo;
}

int Horario::compHorario(const Horario& h){
    if (hora == h.hora && minuto == h.minuto && segundo == h.segundo)
        return 0;
    if (hora != h.hora){
        if(hora < h.hora) 
            return -1;
        else if (hora > h.hora)
            return 1;
    }
    else if (hora == h.hora){
        if(minuito < h.minuto)
            return -1;
        else if(minuto > h.minuto)
            return 1;
        else if (segundo < h.segundo)
            return -1
        else if (segundo > h.segundo)
            return 1;
    }
}

int Horario::difSegundos(const Horario& h){
    int segundosNaHora = 3600;
    int segundosNoMinuto = 60;
    int difSegundos;

    return difSegundos = ((hora*segundosNaHora)+(minutos*segundosNoMinutos)+segundo) - ((h.hora*segundosNaHora)+(h.minutos*segundosNoMinutos)+h.segundo)
}

void Horario::setHora(int h){
    hora = h;
}

void Horario::setMinuto(int m){
    minuto = m;
}

void Horario::setSegundo(int s){
    segundo = s;
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

void Horario::imprime(){
    cout << hora << ":" << minuto << ":" << segundo << endl;
}