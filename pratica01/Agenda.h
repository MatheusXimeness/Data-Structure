#ifndef AGENDA_H
#define AGENDA_H


class ItemAgenda {
    public:
        ItemAgenda();
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
    public:
        Agenda();
        insereItem(const ItemAgenda &);
        compromissosData(const Data &);
};