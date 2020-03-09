/*
    Aluno: Michael Canesche - 68064
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ostream>
#include <istream>

#include "Horario.h"
#include "Data.h"
#include "Agenda.h"

using namespace std;

ItemAgenda::ItemAgenda(){

}

ItemAgenda::ItemAgenda(string dc, Data dt, Horario hr)
    : d(dt.getDia(),dt.getMes(),dt.getAno()),
      h(hr.getHora(),hr.getMinuto(),hr.getSegundo())    
{
    desc = dc;
}

ItemAgenda::ItemAgenda(const ItemAgenda &it)
    : d(it.d), h(it.h)
{
    desc = it.desc;
}
        
void ItemAgenda::setDesc(string dc){

    desc = dc;

}

void ItemAgenda::setData(Data dt){
    
    d = dt;    
    
}

void ItemAgenda::setHorario(Horario hr){

     h = hr;   
    
}

string ItemAgenda::getDesc(){
    
    return desc;    
    
}

Data ItemAgenda::getData(){
    
    return d;    
    
}

Horario ItemAgenda::getHorario(){

    return h;

}

void ItemAgenda::imprime(){

    cout << getData() << " - " << getHorario() << " - " << getDesc() << endl;

}

Agenda::Agenda(){
    
}

istream& operator>>(istream &is, ItemAgenda& it){
  
  Data d;
  Horario h;
  string descricao;

  cout << "Data: ";
  is >> d;
  cout << endl;
  cout << "Horario: ";
  is >> h;
  cout << "Descricao : ";
  is >> descricao;

  it.setData(d);
  it.setHorario(h);
  it.setDesc(descricao);

  return is;
}

ostream& operator<<(ostream &os, ItemAgenda it){
	// imprime os horarios
    os << it.getData() << " - " << it.getHorario() << " - " << it.getDesc();
    return os;
}

void Agenda::inserirItem(ItemAgenda it){

    if(tamAgenda >= 999)
        cout << "Espaço insuficiente na Agenda";
    else{
        agenda[tamAgenda] = it;    
        tamAgenda++;
    }
        
}

void Agenda::compromissosData(Data d){

    cout << "Compromissos na data " << d << "\n";
    int i;
    for(i = 0; i < tamAgenda; i++){
    	// se a diferença do dia for o mesmo do dia requerido, entra na agenda
        if(agenda[i].getData().difDias(d) == 0)
            cout << agenda[i] << endl;
    }

}

ostream& operator<<(ostream &out, Agenda ag)
{
    cout << " --- Compromissos na Agenda ---\n";
    int i;
    for(i = 0; i < ag.tamAgenda; i++){
        cout << ag.agenda[i] << endl;    
    }
    return out;
}

