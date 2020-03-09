/* -------------------- File Teste1Agenda-Alt.cpp ---------------
    Programa para testar a as classes Data, Horario e Agenda
    descritas no diagrama UML da primeira aula pratica de INF213

    Verifica a consistencia dos valores dos objetos de cada classe

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

   Data d1(33,03,2017);
   Data d2(10,14,2017);
   Data d3(02,05,2016);

   Horario h1(27,0,0);
   Horario h2(8,62,0);
   Horario h3(16,0,-4);

   ItemAgenda it1("Item 1",d1,h1);
   ItemAgenda it2("Item 2",d2,h2);
   ItemAgenda it3("Item 3",d3,h3);

   Agenda ag;

   ag.inserirItem(it1);
   ag.inserirItem(it2);
   ag.inserirItem(it3);

   cout<< "\n";

   cout << ag << endl;

   return 0;

}


/* --------------------------------------------------------
                    RESULTADO ESPERADO

33 eh invalido para o campo hora; foi arredondado para 30
14 eh invalido para o campo hora; foi arredondado para 12
2016 eh invalido para o campo hora; foi arredondado para 2017
27 eh invalido para o campo hora; foi arredondado para 23
62 eh invalido para o campo hora; foi arredondado para 59
-4 eh invalido para o campo hora; foi arredondado para 0

 --- Compromnissos na Agenda ---
30/3/2017 - 23:0:0 - Item 1
10/12/2017 - 8:59:0 - Item 2
2/5/2017 - 16:0:0 - Item 3

*/
