#include <iomanip>
#include <iostream>
#include <ostream>
#include <istream>

#include "Data.h"

using namespace std;

Data::Data(int d, int m, int a)
{
    setDia(d);
    setMes(m);
    setAno(a);
}

Data::Data(const Data &dt) {
  ano = dt.ano;
  mes = dt.mes;
  dia = dt.dia;
}

void Data::imprime()
{
  cout << this << endl;
}

void Data::setDia(int d)
{
  if (d < 1 || d > 30) {
    cerr << d << " eh invalido para o campo dia; foi arredondado para ";
    (d < 1) ? d = 1 : d = 30;
    cerr << d << endl;
  }

  dia = d;
}

void Data::setMes(int m)
{
  if (m < 1 || m > 12) {
    cerr << m << " eh invalido para o campo mes; foi arredondado para ";
    (m < 1) ? m = 1 : m = 12;
    cerr << m << endl;
  }

  mes = m;
}

void Data::setAno(int a)
{
  if (a < 2017 || a > 2020) {
    cerr << a << " eh invalido para o campo ano; foi arredondado para ";
    (a < 2017) ? a = 2017 : a = 2020;
    cerr << a << endl;
  }

   ano = a;
}

int Data::getDia() const
{
  return dia;
}

int Data::getMes() const
{
  return mes;
}

int Data::getAno() const
{
  return ano;
}

int Data::compData(Data dma)
{
  int dif = difDias(dma);
  if (dif > 0)
     return +1;
  else if (dif < 0)
     return -1;
  else
     return 0;
}

int Data::difDias(Data dma)
{
  return (ano - dma.ano) * 360 + (mes - dma.mes)*30 + (dia - dma.dia);
}

istream& operator>>(istream &in, Data &dat)
{
  int d, m, a;

  if(!in)
    return in;

  cout << "Dia: ";
  cin >> d;
  cout << "Mes: ";
  cin >> m;
  cout << "Ano: ";
  cin >> a;

  dat.setDia(d);
  dat.setMes(m);
  dat.setAno(a);

  return in;
}

ostream& operator<<(ostream &out, Data dat)
{
    out << setw(2) << setfill('0') << dat.getDia() << "/"
    << setw(2) << setfill('0') << dat.getMes() << "/"
    << setw(4) << setfill('0') << dat.getAno();
    
    return out;
}
