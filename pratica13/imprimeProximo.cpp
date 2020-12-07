#include<iostream>
using namespace std;
#include "MySet.h"

int main(){
    MySet<long long int> bd;
    char comando;
    long long int n;
    while(cin >> comando >> n){
        if(comando == 'C'){
            bd.insert(n);
        } else if( comando == 'S'){
            MySet<long long int>::iterator it = bd.find(n);

            if(it == bd.end()){ //nao tem numero mairo
                cout << "FALHA" << endl;
                continue;
            }
            it ++;
            if(it == bd.end()){ //nao tem sucessor
                cout << "FALHA" << endl;
                continue;
            }else cout << *it << endl;
        }

    }
    return 0;
}