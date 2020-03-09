/* -------------------- File Teste1Agenda-Alt.cpp ---------------
    Programa para testar as classes Data, Horario e Agenda
    descritas no diagrama UML da primeira aula pratica de INF213

    Produz o mesmo resultado que Teste1Agenda porem usando uma
    outra forma para preenchimento dosa dados da agenda

    Autor: Marcus V. A. Andrade - 07/03/2017
---------------------------------------------------------------- */


#include <iostream>
#include <string>

using namespace std;

#include "Agenda.h"
#include "Data.h"
#include "Horario.h"

using namespace std;

int main()
{
   Data d[4];
   Horario h[3];
   ItemAgenda it[5];

   d[0].setDia(8); d[0].setMes(3); d[0].setAno(2017);
   d[1].setDia(30); d[1].setMes(3); d[1].setAno(2017);
   d[2].setDia(11); d[2].setMes(5); d[2].setAno(2017);
   d[3].setDia(29); d[3].setMes(6); d[3].setAno(2017);

   h[0].setHora(14);
   h[1].setHora(8);
   h[2].setHora(16);

   it[0].setDesc("Aula pratica - Turma 1 - INF213"); it[0].setData(d[0]); it[0].setHorario(h[0]);
   it[1].setDesc("Primeira prova INF213"); it[1].setData(d[1]); it[1].setHorario(h[1]);
   it[2].setDesc("Segunda prova INF213"); it[2].setData(d[2]); it[2].setHorario(h[2]);
   it[3].setDesc("Terceira prova INF213"); it[2].setData(d[2]); it[2].setHorario(h[2]);
   it[4].setDesc("Aula pratica - Turma 2 - INF213"); it[3].setData(d[0]); it[3].setHorario(h[2]);

   Agenda ag;

   int i;
   for (i=0; i < 4; i++)
      ag.inserirItem(it[i]);

   ag.compromissosData(d[0]);
   cout << "\n";
   ag.compromissosData(d[1]);

   cout<< "\n";

   cout << ag << endl;

   return 0;
}


/* --------------------------------------------------------
                    RESULTADO ESPERADO

 33 eh invalido para o campo dia; foi arredondado para 30
 14 eh invalido para o campo mes; foi arredondado para 12
 2016 eh invalido para o campo ano; foi arredondado para 2017
 27 eh invalido para o campo hora; foi arredondado para 23
 62 eh invalido para o campo minuto; foi arredondado para 59
 -4 eh invalido para o campo segundo; foi arredondado para 0
 
 --- Compromnissos na Agenda ---
 30/03/2017 - 23:00:00 - Item 1
 10/12/2017 - 08:59:00 - Item 2
 02/05/2017 - 16:00:00 - Item 3
 

*/
