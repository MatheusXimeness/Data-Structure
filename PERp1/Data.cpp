#include<iostream>
#include "Data.h"
using namespace std;

Data::Data(d, m, a){
    setDia(d);
    setMes(m);
    setAno(a);
}

Data::Data(const Data& dt){
    dia = dt.dia;
    mes = dt.mes;
    ano = dt.ano;
}

void Data::setDia(int d){
    if(d>=1 && d<= 30)
        dia = d;
    else{
        if(d<1)
            dia = 1;
        else if(d>30)
            dia = 30;
        }
    }


void Data::setMes(int m){
    if(m>=1 && m<= 12)
        mes = m;
    else{
        if(m<1)
            mes = 1;
        else if(m>12)
            mes = 12;
        }
}

void Data::setAno(int a){
    if(d>=2018 && d<= 2020)
        ano = a;
    else{
        if(a<2018)
            ano = 2018;
        else if(a>2020)
            ano = 2020;
        }
}

int Data::getDia() const{
    return dia;
}

int Data::getMes() const{
    return mes;
}

int Data::getAno() const{
    return ano;
}

int Data::compData(const Data& dt){ // ver se data é menor, igual ou maior do que o objeto passado
    if(difDias(dt) > 0)
        return 1;
    else if(difDias(dt) < 0)
        return -1;
    else 
        return 0;
}

int Data::difDias(const Data& dt){ // a diferenca em dias entre seu objeto e o objeto passado como parâmetro
    int difDias = (dt.ano*365 + 30*(dt.mes-1) + dt.dia) - (ano*365 + 30*(mes-1) + dia);
    return difDias;
}

void Data::imprime(){
    cout << dia << "/" << mes << "/" << ano << endl;
}


