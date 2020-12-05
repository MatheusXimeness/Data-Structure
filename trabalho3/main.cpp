#include <iostream>
#include <string.h>
#include "MyMap.h"


using namespace std;

int main(){
        
        MyMap<string,int> map;
        string str;
        int tam = 0;

        while(cin>>str){
                map.insert(pair<string,int> (str, tam));
                cout << str << " " << map[str] << endl;
                tam = map.size();
        }
}
