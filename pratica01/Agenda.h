#ifndef AGENDA_H
#define AGENDA_H


#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Data.h"
#include "Horario.h"

class ItemAgenda {

    friend istream& operator>>(std::istream &in, ItemAgenda &it);
    friend ostream& operator<<(std::ostream &out, ItemAgenda it);

    public:
        ItemAgenda(){};
        ItemAgenda(const string &, const Data &, const Horario &);
        ItemAgenda(const ItemAgenda &);
        void setDesc(const string &);
        void setData(const Data &);
        void setHorario(const Horario &);
        string getDesc () const;
        Data getData() const;
        Horario getHorario() const;

    private:
        string descricao; 
        Data d;
        Horario h;
};

class Agenda {

    friend ostream& operator<<(std::ostream &out, Agenda sch);

    public:
        Agenda();
        void inserirItem(const ItemAgenda &);
        void compromissosData(Data) const;
    private:
        int tamAg;
        ItemAgenda *ag;

        void imprimeAg();
};

#endif