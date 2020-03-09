/* -------------------- File Teste1Agenda.cpp -------------------
    Programa para testar as classes Data, Horario e Agenda
    descritas no diagrama UML da primeira aula pratica de INF213

    Autor: Marcus V. A. Andrade - 07/03/2017
---------------------------------------------------------------- */

/*
    Aluno: Michael Canesche - 68064
*/

#include <iostream>
#include <string>

using namespace std;

#include "Agenda.h"
#include "Data.h"
#include "Horario.h"

using namespace std;

int main()
{
   Data d1(7,03,2017);
   Data d2(30,03,2017);
   Data d3(11,05,2017);
   Data d4(29,06,2017);

   Horario h[3] = {Horario(14,0,0), Horario(8,0,0), Horario(16,0,0) };

   ItemAgenda it1("Aula pratica - Turma 1 - INF213",d1,h[0]);
   ItemAgenda it2("Primeira prova INF213",d2,h[1]);
   ItemAgenda it3("Segunda prova INF213",d3,h[1]);
   ItemAgenda it4("Terceira prova INF213",d3,h[1]);
   ItemAgenda it5("Aula pratica - Turma 2 - INF213",d1,h[2]);

   Agenda ag;

   ag.inserirItem(it1);
   ag.inserirItem(it2);
   ag.inserirItem(it3);
   ag.inserirItem(it4);
   ag.inserirItem(it5);

   ag.compromissosData(d1);
   cout << "\n";
   ag.compromissosData(d2);

   cout<< "\n";

   cout << ag << endl;

   cout << "Numero de dias entre a primeira e a segunda prova = " << it3.getData().difDias(it2.getData()) <<
   endl;

   return 0;

}

/* --------------------------------------------------------
                    RESULTADO ESPERADO

Compromissos na data 7/3/2017
7/3/2017 - 14:0:0 - Aula pratica - Turma 1 - INF213
7/3/2017 - 16:0:0 - Aula pratica - Turma 2 - INF213

Compromissos na data 30/3/2017
30/3/2017 - 8:0:0 - Primeira prova INF213

 --- Compromnissos na Agenda ---
7/3/2017 - 14:0:0 - Aula pratica - Turma 1 - INF213
30/3/2017 - 8:0:0 - Primeira prova INF213
11/5/2017 - 8:0:0 - Segunda prova INF213
11/5/2017 - 8:0:0 - Terceira prova INF213
7/3/2017 - 16:0:0 - Aula pratica - Turma 2 - INF213

Numero de dias entre a primeira e a segunda prova = 41

*/
