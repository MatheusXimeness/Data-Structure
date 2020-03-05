#include<iostream>
#include <string.h>
using namespace std;

include "Agenda.h"
include "Data.h"
include "Horario.h"

ItemAgenda::ItemAgeda(){}

ItemAgenda::ItemAgenda(const ItemAgenda & it){
    it.h = getHora();
	it.d = getData();
	it.descricao = getDesc();

}

ItemAgenda::ItemAgenda(const sting & desc, const Data & dt, const Horario & hr){
    setDesc(desc);
    setData(dt);
    setHorario(hr);
}

void ItemAgenda::setDesc(const string & desc){
    strcpy(descricao,desc);
}

void ItemAgenda::setData(const Data & dt){
    Data(dt);
}

void ItemAgenda::setHorario(const Horario & hr){
    Horario(hr);
}

string ItemAgenda::getDesc() const{
    return descricao;
}

Data ItemAgenda::getData() const {
    return d;
}

Horario ItemAgenda::getHorario() const {
    return h;
}

Agenda::Agenda(){}

ItemAgenda Agenda:insereItem(const ItemAgenda& it){

}

Data Agenda::compromissoData(const Data & cmp) {
    
}
