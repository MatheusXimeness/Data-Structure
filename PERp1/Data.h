#ifndef DATA_H
#define DATA_H
#include<iostream>
using namespace std;

class Data{
   
    public:
        // -- Construtores -- //
            Data(int d=1, int m=1, int a=2018); // construtor padrao
            Data(const Data& dt); // construtor por cópia
        // --------------- //
        
        // -- Funções set -- //
         //retorna void. Atualiza, com o parametro recebido, os membros de dados da classe
            void setDia(int);
            void setMes(int);
            void setAno(int);
        // --------------- //

        // -- Funções get -- //
         //retorna int, pois pega os membros de dados da classe e usa para printar ou fazer algum calculo
            int getDia() const;
            int getMes() const;
            int getAno() const;
        // --------------- //

        // -- Funções alternativas -- //
            int compData(const Data&);
            int difDias(const Data&);
            void imprime();
        // --------------- //

    private:
        int dia;
        int mes;
        int ano;
};

#endif