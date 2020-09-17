#include <iostream>
using namespace std;

#include "FigBase.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "Segmento.h"

int main(){

    Retangulo r;
    Circulo c1;
    Circulo c2;
    Segmento s1;
    Segmento s2;
    
    FigBase *p[5];
    
    p[0] = &c1;
    p[1] = &c2;
    p[2] = &r;
    p[3] = &s1;
    p[4] = &s2;

    for(int i=0; i<5;i++){
        cin >> *p[i]; 
    }
    cout << endl;
    for(int i=0; i<5;i++){
        cout << *p[i] << endl;
    }

    Circulo *circuloPtr;;

    for(int i=0;i<5;i++){
            circuloPtr = dynamic_cast <  Circulo * > ( p[ i ] );
            if( circuloPtr != 0 ){
                double oldraio = circuloPtr->getRaio();
                circuloPtr->setRaio(oldraio*2);
                cout << *circuloPtr << endl;
        }
    }

    return 0;
}