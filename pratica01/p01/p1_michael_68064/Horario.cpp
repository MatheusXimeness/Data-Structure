/*
    Aluno: Michael Canesche - 68064
*/
#include "Horario.h"

#include <iostream>
#include <iomanip>
using namespace std;

Horario::Horario(int h, int m, int s){
    
    setHora(h);
    setMinuto(m);
    setSegundo(s);

}

Horario::Horario(const Horario &hr){

    hora = hr.hora;
    minuto = hr.minuto;
    segundo = hr.segundo;

}

void Horario::imprime(){
    
    cout << getHora() << ":" << getMinuto() << ":" << getSegundo(); 

}

void Horario::setHora(int h){

    if(h >= 0 && h < 24)
        hora = h;
    else{
        cout << h << " eh invalido para o campo hora;";
        if(h < 0){
            cout << " foi arredondado para 0";
            hora = 0; 
        }else{
            cout << " foi arredondado para 30";
            hora = 23; 
        }
        cout << endl;
    }

}

void Horario::setMinuto(int m){

    if(m >= 0 && m < 60)
        minuto = m;
    else{
        cout << m << " eh invalido para o campo minuto;";
        if(m < 0){
            cout << " foi arredondado para 1";
            minuto = 0; 
        }else{
            cout << " foi arredondado para 59";
            minuto = 59; 
        }
        cout << endl;
    
    } 
    
}

void Horario::setSegundo(int s){

    if(s >= 0 && s < 60)
        segundo = s;
    else{
        cout << s << " eh invalido para o campo segundo;";
        if(s < 0){
            cout << " foi arredondado para 0";
            segundo = 0; 
        }else{
            cout << " foi arredondado para 59";
            segundo = 59; 
        }
        cout << endl;
    } 
    
}

int Horario::getHora() const{

    return hora;    
    
}

int Horario::getMinuto() const{
    
    return minuto;    
    
}

int Horario::getSegundo() const{
    
    return segundo;    
    
}

int Horario::compHorario(Horario hms){

    int dif = difSegundos(hms);
    if(dif > 0)
        return 1;
    else if(dif < 0)
        return -1;
    else
        return 0; 

}

int Horario::difSegundos(Horario hms){

    return (hora - hms.hora)*3600 + (minuto - hms.minuto)*60 + (segundo - hms.segundo);

}

istream& operator>>(istream &is, Horario &hms){
  
    int h, m, s;
    
    if(!is)
        return is;

    cout << "Hora: ";
    is >> h;
    cout << "Minuto: ";
    is >> m;
    cout << "Segundo: ";
    is >> s;

    if(!is)
        is.clear();
    else
    {
        hms.setHora(h);
        hms.setMinuto(m);
        hms.setSegundo(s);
    }
    return is;
}

ostream& operator<<(ostream &os, Horario hms) 
{
   os << setw(2) << setfill('0') << hms.getHora() << ":" <<
         setw(2) << setfill('0') << hms.getMinuto() << ":" << 
         setw(2) << setfill('0') << hms.getSegundo();
         
   return os;
}
