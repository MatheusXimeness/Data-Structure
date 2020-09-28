#include "Conjunto2.h"
#include <iostream>


int main(){
    int n;
    cout << "digite o tamanho dos vetores" << "\n";
    cin >> n;

    Conjunto<int> A(n), B(n), C;
    for(int i=0;i<n;i++){
        A.insere(i);
        B.insere(i);
    }
    C = A + B;
    cout << C.pertence(10) << "\n";

    return 0;
}
