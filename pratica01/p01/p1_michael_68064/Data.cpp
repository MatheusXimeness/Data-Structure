/*
    Aluno: Michael Canesche - 68064
*/
#include "Data.h"

#include <iostream>
#include <iomanip>

using namespace std;

Data::Data(int d, int m, int a){
    
    setDia(d);
    setMes(m);
    setAno(a);

}

Data::Data(const Data &dt){

    dia = dt.dia;
    mes = dt.mes;
    ano = dt.ano;

}

void Data::imprime(){
    
    cout << getDia() << "/" << getMes() << "/" <<  getAno() << endl; 

}

void Data::setDia(int d){
    
    if(d < 1 || d > 30){
        cerr << d << " eh invalido para o campo hora; foi arredondado para";
        (d < 1) ? d = 1 : d = 30;
        cerr << d << endl;
    }
    dia = d;
}

void Data::setMes(int m){

    if (m < 1 || m > 12) {
    cerr << m << " eh invalido para o campo mes; foi arredondado para ";
    (m < 1) ? m = 1 : m = 12;
    cerr << m << endl;
  }

  mes = m;
    
}

void Data::setAno(int a){

    if (a < 2017 || a > 2020) {
    cerr << a << " eh invalido para o campo ano; foi arredondado para ";
    (a < 2017) ? a = 2017 : a = 2020;
    cerr << a << endl;
  }

   ano = a;
    
}

int Data::getDia(){

    return dia;    
    
}

int Data::getMes(){
    
    return mes;    
    
}

int Data::getAno(){
    
    return ano;    
    
}

int Data::compData(Data dma){

    int dif = difDias(dma);
    if(dif > 0)
        return 1;
    else if(dif < 0)
        return -1;
    else
        return 0; 

}

int Data::difDias(Data dma){

    return (ano - dma.ano)*360 + (mes - dma.mes)*30 + (dia - dma.dia);

}

istream& operator>>(istream &is, Data &data)
{
	int d, m, a;

    if(!is)
        return is;

    cout << "Dia: ";
	is >> d;
	cout << "Mes: ";
	is >> m;
	cout << "Ano: ";
	is >> a;

	data.setDia(d);
	data.setMes(m);
	data.setAno(a);
  
	return is;
}

ostream& operator<<(ostream &os, Data data){
    os << setw(2) << setfill('0') << data.getDia() << "/" << 
          setw(2) << setfill('0') << data.getMes() << "/" << 
          setw(4) << setfill('0') << data.getAno();
    return os;
}
