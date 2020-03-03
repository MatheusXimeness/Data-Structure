#include<iostream>
using namespace std;

include "Data.h"


Data::Data(int d, int m, int a){
    setDia(int d);
    setMes(int m);
    setAno(int a);
}

Data::Data(const Data& d){
    dia = d.dia;
    mes = d.mes;
    ano = d.ano;
}

int Data::compData(const Data& d){
    // if (dia == d.dia && mes == d.mes && ano == d.ano)
    //     return 0;
    // if (ano != d.ano){
    //     if(ano < d.ano) 
    //         return -1;
    //     else if (ano > d.ano)
    //         return 1;
    // }
    // else if (ano == d.ano){
    //     if(mes < d.mes)
    //         return -1;
    //     else if(mes > d.mes)
    //         return 1;
    //     else if (dia < d.dia)
    //         return -1
    //     else if (dia > d.dia)
    //         return 1;
    // }

    if (difDias(d) == 0 )
        return 0;
    else if(difDias(d) > 0)
        return 1;
    else
        return -1;
}

int Data::difDias(const Data& d){
    int diasNoAno = 365;
    int diasNoMes = 30;
    int difDias;

    return difDias = ((diasNoAno*ano)+(diasNoMes*mes)+dia) - ((diasNoAno*d.ano)+(diasNoMes*d.mes)+d.dia)
    
}

void Data::setDia(int d){
    dia = d;
}

void Data::setMes(int m){
    mes = m;
}

void Data::setAno(int a){
    ano = a;
}

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAno() const {
    return ano;
}

void Data::imprime() {
    cout << dia << "/" << mes << "/" << ano << endl;
}