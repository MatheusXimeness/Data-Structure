#include <vector>
#include <iostream>
#include <cstring>
#include <istream>
#include <ostream>
#include <string>

#include "Horario.h"
#include "Data.h"
#include "Agenda.h"

using namespace std;

ItemAgenda::ItemAgenda(string dc, Data dt, Horario hr)
  : d(dt.getDia(), dt.getMes(), dt.getAno()),
    h(hr.getHora(), hr.getMinuto(), hr.getSegundo())
{
  desc = dc;
}

ItemAgenda::ItemAgenda(const ItemAgenda &it)
  : d(it.d), h(it.h)
{
  desc = it.desc;
}


void ItemAgenda::setDesc(string dc)
{
  desc = dc;
}

void ItemAgenda::setData(Data d)
{
  this->d = d;
}

void ItemAgenda::setHorario(Horario h)
{
  this->h = h;
}

string ItemAgenda::getDesc()
{
  return desc;
}

Data ItemAgenda::getData()
{
  return d;
}

Horario ItemAgenda::getHorario()
{
  return h;
}

istream& operator>>(istream &in, ItemAgenda& it)
{
  Data d;
  Horario h;
  string descricao;

  cout << "Data: ";
  cin >> d;
  cout << endl;
  cout << "Horario: ";
  cin >> h;
  cout << "Descricao : ";
  cin >> descricao;

  it.setData(d);
  it.setHorario(h);
  it.setDesc(descricao);

  return in;
}

ostream& operator<<(ostream &out, ItemAgenda it)
{
    out << it.getData() << " - " << it.getHorario() << " - " << it.getDesc();

    return out;
}

Agenda::Agenda()
{
   agSize = 0;
   ag = new ItemAgenda[100];
}

void Agenda::inserirItem(ItemAgenda it)
{
  if (agSize == 99)
     cerr << "*** AGENDA CHEIA *** \n";
  else {
     ag[agSize] = it;
     agSize++;
  }
}

void Agenda::compromissosData(Data d)
{
  cout << "Compromissos na data " << d << "\n";

  for(int i = 0; i < agSize; ++i)
  {
      if(ag[i].getData().compData(d) == 0)
         cout << ag[i] << endl;
  }

}

void Agenda::impAgenda() {
    cout << this;
}

ostream& operator<<(std::ostream &out, Agenda sch) {
  cout << " --- Compromnissos na Agenda --- \n";
    
  for(int i = 0; i < sch.agSize; ++i)
    cout << sch.ag[i] << endl;

  return out;
}


