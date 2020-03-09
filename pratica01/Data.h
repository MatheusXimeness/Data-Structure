#ifndef DATA_H
#define DATA_H
#include<iostream>
using namespace std;

class Data {

    friend ostream & operator<<(std::ostream &, const Data &);
	friend istream & operator>>(std::istream &, Data &);

    public:

        Data(int d = 1, int m = 1, int a = 2018);
        Data(const Data&);

        void setDia(int d);
        void setMes(int m);
        void setAno(int a);

        int getDia() const;
        int getMes() const;
        int getAno() const;

        int compData(const Data&);
        int difDias(const Data&);

        void imprime();

    private:

        int dia;
        int mes;
        int ano;
};

#endif