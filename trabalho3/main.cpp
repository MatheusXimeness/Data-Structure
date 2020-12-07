#include <iostream>
#include <string.h>
#include <sstream>
#include "MyMap.h"

using namespace std;


string maiorFreqMap1(MyMap<string,int> &map1, string &lastWord){
        int maiorFreq = 0;
        string wordFreqMax;
        for( MyMap<string,int>::iterator itMap1 = map1.begin() ;itMap1!=map1.end();itMap1++){
                if((*itMap1).second > maiorFreq && (*itMap1).first != lastWord){
                        maiorFreq =  (*itMap1).second;
                        wordFreqMax = (*itMap1).first;
                }
        }
        return wordFreqMax;
}
string maiorFreqMap2(MyMap<string,MyMap<string,int>> &map2, string &lastWord){
        MyMap<string, MyMap<string, int>>::iterator itMap2 = map2.begin();
        MyMap<string, int>::iterator itMap1_2 = (*itMap2).second.begin();
        int maiorFreq = 0;
        string wordFreqMax;

        for (itMap2 = map2.begin(); itMap2 != map2.end(); itMap2++){
                for (itMap1_2 = (*itMap2).second.begin(); itMap1_2 != (*itMap2).second.end(); itMap1_2++){
                        if((*itMap1_2).second > maiorFreq && (*itMap1_2).first != lastWord){ // se for igual a primeira e a segunda palavra contidas no map --> printa
                                maiorFreq = (*itMap1_2).second;
                                wordFreqMax = (*itMap1_2).first;
                        }
                }
        }
        return wordFreqMax;
}

string maiorFreqMap3(MyMap<string,MyMap<string,MyMap<string,int>>> &map3, string &lastWord){
        MyMap<string, MyMap<string, MyMap<string, int>>>::iterator itMap3 = map3.begin();
        MyMap<string, MyMap<string, int>>::iterator itMap2_3 = (*itMap3).second.begin();
        MyMap<string, int>::iterator it1_3 = (*itMap2_3).second.begin();
        int maiorFreq = 0;
        string wordFreqMax;

        for (itMap3 = map3.begin(); itMap3 != map3.end(); itMap3++){
                for (itMap2_3 = (*itMap3).second.begin(); itMap2_3 != (*itMap3).second.end(); itMap2_3++){
                        for (it1_3 = (*itMap2_3).second.begin(); it1_3 != (*itMap2_3).second.end(); it1_3++){
                                if((*it1_3).second > maiorFreq && (*it1_3).first != lastWord) {  // se for igual a primeira, a segunda e a terceira palavra contidas no map --> printa
                                        maiorFreq = (*it1_3).second;
                                        wordFreqMax = (*it1_3).first;
                                }
                        }
                }
        }
        return wordFreqMax;
}

//função necessária, pois em tempo de execução haverão outras strings que precisarão ser tratadas
void trataPalavra(string &textIN){
        for(int i=0;i<textIN.size();i++){
                if(textIN[i] >= 'A' && textIN[i] <= 'Z') // se for maiuscula
                        textIN[i]+= ' '; // passa para minuscula
        }

        for(int i=0;i<textIN.size();i++){
                bool verificaCaractere = ('a' <= textIN[i] && textIN[i]<= 'z') || (textIN[i]=='-') || (textIN[i] == ' ');
                if(!verificaCaractere) textIN[i] = '\n'; // se for algum caractere especial substitui por '\n'
        }
}

void trataEntrada(stringstream &ss){
       
        string textIN;
        // le a primeira linha do arquivo de teste (COMECO_TREINO)
        getline(cin, textIN);

        while(getline(cin, textIN)){
                if(textIN == "FINAL_TREINO") break; // se chegar no final das sentenças, sai do loop
                
                trataPalavra(textIN);
                
                ss << textIN;
        }
}

void armazenaMap( stringstream &ss, MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2, MyMap<string,MyMap<string,MyMap<string,int>>> &map3){
        string wordSt, wordNd, str; // armazena as três últimas palavras do texto
        int auxInsert = 0; // variavel que auxilia na hora da inserção no map. 
        //caso seja 0: insere no map1; caso seja 1: insere no map 1 e 2; caso seja maior que 1: insere no map 1, 2 e 3


        while(ss>>str){ // enquanto tiver palavras na variavel stringstream
                if(auxInsert == 0){
                        wordSt = str;
                        map1[str]++;
                        
                }
                else if (auxInsert == 1){
                        map1[str]++;
                        map2[wordSt][str]++;
                        wordNd = str;
                        
                } else {
                        map1[str]++;
                        map2[wordNd][str]++;
                        map3[wordSt][wordNd][str]++;
                        // atualizando três últimas
                        wordSt = wordNd;
                        wordNd = str;
                }
                auxInsert++;
        }
}

void fazConsulta(stringstream &ss2, stringstream &ss3, MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2, MyMap<string,MyMap<string,MyMap<string,int>>> &map3){
        // convertendo a string que contém a quantidade de consultas para int 
        string numColsutas, str, wordSt, wordNd, wordRd, str2;
        int retiraInt;
        ss2 >> numColsutas;
        ss3 >> retiraInt;
        int K = stoi(numColsutas);
        int auxConsulta = 0; //auxilia no print das consultas
      
        while(ss3 >> str2){ // descobre qual o numero de palavras que a consulta irá se basear
                if(auxConsulta == 0){
                        wordSt = str2; //wordFirst = primeira palavra
                        trataPalavra(wordSt);
                }
                else if(auxConsulta == 1){
                        wordNd = str2; //wordSecond = segunda palavra
                         trataPalavra(wordNd);
                }
                else{
                        wordRd = str2; //wordThird = terceira palavra
                         trataPalavra(wordRd);
                }
                auxConsulta++;
        }

        int sai = 0; // caso tenha entrado no if do map3 com duas palavras --> sai++ --> não volta outra vez
        
        while(ss2 >> str){ // enquanto tiver palavras na ss2
                if(K==0) break; // ou vai até o número de consultas desejado
                
                //Se tiver uma palavra --> usa MAP 1 e MAP 2
                if (auxConsulta == 1){
                        
                        // --------------------- MAP 1 --------------------- //
                        // printa a primeira palavra com sua frequencia
                                for( MyMap<string,int>::iterator itMap1 = map1.begin() ;itMap1!=map1.end();itMap1++){
                                        if(str == (*itMap1).first){
                                                cout << (*itMap1).first << " (" << (*itMap1).second << ")" << endl;
                                        }
                                }
                        // ---------------------  --------------------- //

                        // --------------------- MAP 2 --------------------- //
                                MyMap<string, MyMap<string, int>>::iterator itMap2 = map2.begin();
                                MyMap<string, int>::iterator itMap1_2 = (*itMap2).second.begin();
                                
                        // em seguida printa as palavras com base na palavra dada
                                for (itMap2 = map2.begin(); itMap2 != map2.end(); itMap2++){
                                        for (itMap1_2 = (*itMap2).second.begin(); itMap1_2 != (*itMap2).second.end(); itMap1_2++){
                                                if((*itMap2).first == wordSt){  // se for igual a primeira contida no map --> printa
                                                        cout << (*itMap2).first << " " << (*itMap1_2).first << " (" << (*itMap1_2).second << ")" <<"\n";
                                                        K--;
                                                }
                                        }
                                }
                        // ------------------------------------------ //
                } 

                // se tiver duas palavras --> usa MAP 2 e MAP 3
                else if(auxConsulta==2) { 
                        // --------------------- MAP 2 --------------------- //
                                if(sai==0){
                                        MyMap<string, MyMap<string, int>>::iterator itMap2 = map2.begin();
                                        MyMap<string, int>::iterator itMap1_2 = (*itMap2).second.begin();

                                        for (itMap2 = map2.begin(); itMap2 != map2.end(); itMap2++){
                                                for (itMap1_2 = (*itMap2).second.begin(); itMap1_2 != (*itMap2).second.end(); itMap1_2++){
                                                        if((*itMap2).first == wordSt && (*itMap1_2).first == wordNd){ // se for igual a primeira e a segunda palavra contidas no map --> printa
                                                                cout << (*itMap2).first << " " << (*itMap1_2).first << " (" << (*itMap1_2).second << ")" <<"\n";
                                                        }
                                                }
                                        }
                                }
                        // ------------------------------------------ //

                        // --------------------- MAP 3 --------------------- //
                                MyMap<string, MyMap<string, MyMap<string, int>>>::iterator itMap3 = map3.begin();
                                MyMap<string, MyMap<string, int>>::iterator itMap2_3 = (*itMap3).second.begin();
                                MyMap<string, int>::iterator it1_3 = (*itMap2_3).second.begin();

                                for (itMap3 = map3.begin(); itMap3 != map3.end(); itMap3++){
                                        if(sai>0) break;
                                        for (itMap2_3 = (*itMap3).second.begin(); itMap2_3 != (*itMap3).second.end(); itMap2_3++){
                                                for (it1_3 = (*itMap2_3).second.begin(); it1_3 != (*itMap2_3).second.end(); it1_3++){
                                                        if((*itMap3).first == wordSt &&  (*itMap2_3).first == wordNd){  // se for igual a primeira e a segunda palavra contidas no map --> printa
                                                                cout << (*itMap3).first << " " << (*itMap2_3).first << " " << (*it1_3).first <<  " (" << (*it1_3).second << ")" <<"\n";
                                                                K--;
                                                                sai++;
                                                        }
                                                       
                                                }
                                        }
                                }
                        // ------------------------------------------ //
                }
                //caso haja três palavras --> utiliza só o map 3
                else if(auxConsulta == 3) {

                        // --------------------- MAP 3 --------------------- //
                                MyMap<string, MyMap<string, MyMap<string, int>>>::iterator itMap3 = map3.begin();
                                MyMap<string, MyMap<string, int>>::iterator itMap2_3 = (*itMap3).second.begin();
                                MyMap<string, int>::iterator it1_3 = (*itMap2_3).second.begin();

                                for (itMap3 = map3.begin(); itMap3 != map3.end(); itMap3++){
                                        if(sai>0) break;
                                        for (itMap2_3 = (*itMap3).second.begin(); itMap2_3 != (*itMap3).second.end(); itMap2_3++){
                                                for (it1_3 = (*itMap2_3).second.begin(); it1_3 != (*itMap2_3).second.end(); it1_3++){
                                                        if((*itMap3).first == wordSt &&  (*itMap2_3).first == wordNd && (*it1_3).first == wordRd) {  // se for igual a primeira, a segunda e a terceira palavra contidas no map --> printa
                                                                        cout << (*itMap3).first << " " << (*itMap2_3).first << " " << (*it1_3).first <<  " (" << (*it1_3).second << ")" <<"\n";
                                                                        K--;
                                                                        sai++;
                                                        }
                                                }
                                        }
                                }
                        // ------------------------------------------ //
                }
        }
}

void gerar(stringstream &ss2, stringstream &ss3, MyMap<string,int> &map1, MyMap<string,MyMap<string,int>> &map2, MyMap<string,MyMap<string,MyMap<string,int>>> &map3){
        // convertendo a string que contém a quantidade de palavras que serão geradas para int
        /*string numGerar, option; // default ou randon
        ss2 >> numGerar;
        ss2 >> option;
        int K = stoi(numGerar);

        string tiraInt, tiraOpcao;
        ss3 >> tiraInt;
        ss3 >> tiraOpcao;
        
        int auxGerar = 0; //auxilia no print das consultas
        string wordSt, wordNd, wordRd, str;
        while(ss3 >> str){ // descobre qual o numero de palavras que a consulta irá se basear
                if(auxGerar == 0){
                        wordSt = str; //wordFirst = primeira palavra
                        trataPalavra(wordSt);
                }
                else if(auxGerar == 1){
                        wordNd = str; //wordSecond = segunda palavra
                        trataPalavra(wordNd);
                }
                else{
                        wordRd = str; //wordThird = terceira palavra
                        trataPalavra(wordRd);
                }
                auxGerar++;
        }
        int naoPrintaRepetido =0;
        if(option == "padrao"){
                while(K!=0){
                        if(auxGerar == 1){
                                if(naoPrintaRepetido == 0){
                                        cout << wordSt << " " << maiorFreqMap1(map1,wordSt) << " ";
                                        wordSt = maiorFreqMap1(map1,wordSt);
                                        naoPrintaRepetido++;
                                } else { 
                                        cout << maiorFreqMap2(map2,wordSt) << " ";
                                        wordSt = maiorFreqMap1(map1,wordSt);
                                        K--;
                                }

                        } else if (auxGerar == 2){
                                if(naoPrintaRepetido == 0){
                                        cout << wordSt << " " << wordNd << " " << maiorFreqMap2(map2,wordNd) << " ";
                                        wordNd = maiorFreqMap2(map2,wordNd);
                                        naoPrintaRepetido++;
                                } else {
                                        cout << maiorFreqMap2(map2,wordNd) << " ";
                                        wordNd = maiorFreqMap2(map2,wordNd);
                                        K--;
                                }
                        } /*else if (auxGerar == 3){
                                cout << wordSt << " "<< wordNd << " " << wordRd << " " << maiorFreqMap3(map3,wordRd) << " ";
                                wordSt;
                                K--;
                        }
                }

        } else if (option == "aleat"){
                if(auxGerar == 1){

                } else if (auxGerar == 2){

                } else if (auxGerar == 3){
                        
                }
        }*/
}

int main(){

        // criando Maps e variável para auxiliar leitura
        stringstream ss;
        MyMap<string,int> map1;
        MyMap<string,MyMap<string,int>> map2;
        MyMap<string,MyMap<string,MyMap<string,int>>> map3;

        // tratamento de entrada
        trataEntrada(ss);

        // armazenamento no map
        armazenaMap(ss, map1, map2, map3);
        
        string command; // consultar ou gerar
        string commandLine; // linha compelta

        while(getline(cin, commandLine)){

                stringstream ss2, ss3; // variavel que vai auxiliar na continuação da leitura do arquivo
                ss2 << commandLine; // recebe a linha toda
                ss2 >> command; // passa apenas o comando
                ss3 << commandLine;
                ss3 >> command;

                if(command == "consultar"){
                        fazConsulta(ss2, ss3, map1, map2, map3);
                        cout << endl;
                } else if (command == "gerar"){
                        gerar(ss3, ss2, map1, map2, map3);
                        cout << endl;
                }
        }
}
