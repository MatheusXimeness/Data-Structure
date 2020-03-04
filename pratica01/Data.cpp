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
    if(d<1 || d>30){
        if(d<1)
            d = 1;
        if(d>30)
            d = 30;
    }
    dia = d;
}

void Data::setMes(int m){
    if(m<1 || m>12){
        if(m<1)
            m = 1;
        if(m>12)
            m = 30;
    }

    mes = m;
}

void Data::setAno(int a){
    if(a<2018 || a>2020){
        if(a<2018)
            a = 2018;
        if(a>2020)
            a = 2020;
    }

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
    	cout << getDia() << "/" << getMes() << "/" << getAno() << endl;
}

ostream & operator<<(ostream &cout, const Data &dt){
	dt.imprime();
	
	return cout;
}

istream & operator>>(istream &cin, Data &dt){
	dt.le();
	
	return cin;
}

void Data::le(){
	int d,m,a;
	cout << "dia: ";
	cin >> d; setDia(d);
	cout << "mes: ";
	cin >> m; setMes(m);
	cout << "ano: ";
	cin >> a; setAno(a);
}
