#include <vector>
#include <iostream>
#include <cstring>
#include <istream>
#include <ostream>
#include <string>
using namespace std;

#include "Agenda.h"
#include "Data.h"
#include "Horario.h"


ItemAgenda::ItemAgenda(const ItemAgenda & it)
: d(it.d), h(it.h)
{
    descricao = it.descricao;
}

ItemAgenda::ItemAgenda(const string & desc, const Data & dt, const Horario & hr)
: d(dt.getDia(), dt.getMes(), dt.getAno()),
  h(hr.getHora(), hr.getMinuto(), hr.getSegundo())
{
    descricao = desc;
}

void ItemAgenda::setDesc(const string &dc)
{
  descricao = dc;
}

void ItemAgenda::setData(const Data &d)
{
  this->d = d;
}

void ItemAgenda::setHorario(const Horario &h)
{
  this->h = h;
}

string ItemAgenda::getDesc() const{
    return descricao;
}

Data ItemAgenda::getData() const {
    return d;
}

Horario ItemAgenda::getHorario() const {
    return h;
}

istream& operator>>(istream &in, ItemAgenda& it)
{
  Data d;
  Horario h;
  string descricao;

  cin >> d;
  cout << endl;
  cin >> h;
  cin >> descricao;

  it.setData(d);
  it.setHorario(h);
  it.setDesc(descricao);

  return in;
}

ostream& operator<<(ostream &out, ItemAgenda it)
{

    out << it.getHorario() << " " << it.getDesc();

    return out;
}


Agenda::Agenda(){
    tamAg = 0;
    ag = new ItemAgenda[100];
}

void Agenda::inserirItem(const ItemAgenda& it){
      if (tamAg == 99)
        cout << "full" << endl;
  else {
     ag[tamAg] = it;
     tamAg++;
    }
}

void Agenda::compromissosData( Data d) const {

  for(int i = 0; i < tamAg; ++i)
  {
      if(ag[i].getData().compData(d) == 0)
         cout << ag[i] <<endl;
  }
}

ostream& operator<<(std::ostream &out, Agenda sch) {
  cout << "Compromnissos" << endl;
    
  for(int i = 0; i < sch.tamAg; ++i)
    cout << sch.ag[i] << endl;

  return out;
}