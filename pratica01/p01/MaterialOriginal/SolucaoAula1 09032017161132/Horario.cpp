#include <istream>
#include <iostream>
#include <ostream>
#include <istream>
#include <iomanip>
#include <cstdlib>

#include "Horario.h"

using namespace std;

Horario::Horario(int h, int m, int s)
{
    setHora(h);
    setMinuto(m);
    setSegundo(s);
}

Horario::Horario(const Horario &hr) {
  hora = hr.hora;
  minuto = hr.minuto;
  segundo = hr.segundo;
}

void Horario::imprime()
{
  cout << this << endl;
}

void Horario::setHora(int h)
{
  if (h < 0 || h > 23) {
    cerr << h << " eh invalido para o campo hora; foi arredondado para ";
    (h < 0) ? h = 0 : h = 23;
    cerr << h << endl;
  }
  hora = h;
}

void Horario::setMinuto(int m)
{
  if (m < 0 || m > 59) {
    cerr << m << " eh invalido para o campo minuto; foi arredondado para ";
    (m < 0) ? m = 0 : m = 59;
    cerr << m << endl;
  }

  minuto = m;
}

void Horario::setSegundo(int s)
{
  if (s < 0 || s > 59) {
    cerr << s << " eh invalido para o campo segundo; foi arredondado para ";
    (s < 0) ? s = 0 : s = 59;
    cerr << s << endl;
  }

  segundo = s;
}

int Horario::getHora() const
{
  return hora;
}

int Horario::getMinuto() const
{
  return minuto;
}

int Horario::getSegundo() const
{
  return segundo;
}

int Horario::compHorario(Horario hms)
{
  int dif = difSegundos(hms);
  if (dif > 0)
     return +1;
  else if (dif < 0)
     return -1;
  else
     return 0;
}


int Horario::difSegundos(Horario hms)
{
  return (hora-hms.hora)*3600 + (minuto-hms.minuto)*60 + (segundo-hms.segundo);
}

istream& operator>>(istream &in, Horario &hms)
{
  int h, m, s;

  if(!in)
    return in;

  cout << "Hora: ";
  cin >> h;
  cout << "Minuto: ";
  cin >> m;
  cout << "Segundo: ";
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
    out << setw(2) << setfill('0') << hms.hora << ":"
    << setw(2) << setfill('0') << hms.minuto << ":"
    << setw(2) << setfill('0') << hms.segundo;
    
    return out;
}
