#ifndef DATA_H
#define DATA_H

class Data {
    public:

        Data(int d = 1, int m = 1, int a = 2018);
        Data(const Data&);

        void setDia(int d);
        void setMes(int m);
        void setAno(int a);

        int getDia();
        int getMes();
        int getAno();

        int compData(const Data&);
        int difDias(const Data&);

        void imprime();

    private:

        int dia;
        int mes;
        int ano;
};