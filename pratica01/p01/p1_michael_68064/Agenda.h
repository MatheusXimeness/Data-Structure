/*
    Aluno: Michael Canesche - 68064
*/

#ifndef AGENDA_H
#define AGENDA_H

#include <iostream>
#include <string>

#include "Data.h"
#include "Horario.h"

using namespace std;

class ItemAgenda{

    private:
        string desc;
        Data d;
        Horario h; 
    public:
        ItemAgenda();
        ItemAgenda(string dc, Data dt, Horario hr);
        ItemAgenda(const ItemAgenda &it);
        void setDesc(string dc);
        void setData(Data dt);
        void setHorario(Horario hr);
        string getDesc();
        Data getData();
        Horario getHorario();
        void imprime();
    
};

class Agenda
{
    friend ostream& operator<<(ostream &out, Agenda ag);
    
    private:
        ItemAgenda agenda[1000];
        int tamAgenda;
    public:
        Agenda();
        void inserirItem(ItemAgenda it);
        void compromissosData(Data d);
};

istream& operator>>(istream &is, ItemAgenda &it);
ostream& operator<<(ostream &os, ItemAgenda it);


#endif
