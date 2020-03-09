#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Data.h"
#include "Horario.h"

class ItemAgenda
{
  friend istream& operator>>(std::istream &in, ItemAgenda &it);
  friend ostream& operator<<(std::ostream &out, ItemAgenda it);

  public:
    ItemAgenda() { };
    ItemAgenda(string desc, Data d, Horario h);
    ItemAgenda(const ItemAgenda &it);
    void setDesc(string desc);
    void setData(Data d);
    void setHorario(Horario h);
    string getDesc();
    Data getData();
    Horario getHorario();
  private:
    string desc;
    Data d;
    Horario h;
};


class Agenda
{
  friend ostream& operator<<(std::ostream &out, Agenda sch);

  public:
    Agenda();
    void inserirItem(ItemAgenda it);
    void compromissosData(Data d);
  private:
    int agSize;
    ItemAgenda *ag;

    void impAgenda();
};



#endif
