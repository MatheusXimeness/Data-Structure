/*
    Aluno: Michael Canesche - 68064
*/

#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <iomanip>
#include <ostream>
#include <istream>

using namespace std;

class Data{
    
    private:
        int dia, mes, ano;
    public:
        Data(int d = 1, int m = 1, int a = 2017);
        Data(const Data &dt);
        void imprime();
        void setDia(int d);
        void setMes(int m);
        void setAno(int a);
        int getDia();
        int getMes();
        int getAno();
        int compData(Data dma);
        int difDias(Data dma);

};

istream& operator>>(istream &is, Data &d);
ostream& operator<<(ostream &os, Data d);

#endif
