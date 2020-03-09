#include <istream>
#include <iostream>
#include <ostream>
#include <istream>
#include <iomanip>
#include <cstdlib>
using namespace std;

#include "Horario.h"


Horario::Horario(int h, int m, int s){
    setHora(h);
    setMinuto(m);
    setSegundo(s);
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
        if(minuto < h.minuto)
            return -1;
        else if(minuto > h.minuto)
            return 1;
        else if (segundo < h.segundo)
            return -1;
        else if (segundo > h.segundo)
            return 1;
    }
}

int Horario::difSegundos(const Horario& h){
    int segundosNaHora = 3600;
    int segundosNoMinuto = 60;
    int difSegundos;

    return difSegundos = ((hora*segundosNaHora)+(minuto*segundosNoMinuto)+segundo) - ((h.hora*segundosNaHora)+(h.minuto*segundosNoMinuto)+h.segundo);
}

void Horario::setHora(int h){
     if (h < 0 || h > 23) {
    (h < 0) ? h = 0 : h = 23;
  }
  hora = h;
}

void Horario::setMinuto(int m){
  if (m < 0 || m > 59) {
    (m < 0) ? m = 0 : m = 59;
  }

  minuto = m;
}

void Horario::setSegundo(int s){
  if (s < 0 || s > 59) {
    (s < 0) ? s = 0 : s = 59;
  }

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
    cout << this << endl;
}

istream& operator>>(istream &in, Horario &hms)
{
  int h, m, s;

  if(!in)
    return in;

  cin >> h;
  cin >> m;
  cin >> s;

  if(!in)
    in.clear();
  else
  {
    hms.setHora(h);
    hms.setMinuto(m);
    hms.setSegundo(s);
  }

  return in;
}

ostream& operator<<(ostream &out, Horario hms)
{
    out  << hms.hora << " "
    << hms.minuto << " "
    << hms.segundo;
    
    return out;
}