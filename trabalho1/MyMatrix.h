#ifndef MYMATRIX_H
#define MYMATRIX_H
#include<iostream>
using namespace std;

template<class T>
class MyMatrix;

template<class T>
class MyMatrix{
    public:
        MyMatrix(int,int*,bool);
        MyMatrix(const MyMatrix<T>&);
        ~MyMatrix();
        const MyMatrix &operator=(const MyMatrix<T>&);

        void set(int, int, const T&);
        
        const T &get(const int, const int) const;
        int getNumRows() const { return rows; }
        int getNumElems() const { return size; }
        int getNumCols(int i) const;
        
        void resizeRow(int, int);
        void resizeNumRows(int);
       
        bool isRagged() const;
        
        void convertToRagged();
        void convertToTraditional();
        
        void print() const;

    private:
        int rows, size, *tam, *start; 
        T** matriz;
        T* ragged;
};

// ----------- Construtores/Destrutor ---------- //
// N = número de linhas
// Complexidade dos dois (Tradicional/Ragged)construtores O(N) 
    template<class T>
    MyMatrix<T>::MyMatrix(int numLinhas, int * arrayCol, bool defineShape){
        rows = numLinhas;
        size = 0;
        for(int i=0;i<rows;i++){
            size += arrayCol[i];
        } 
        if(defineShape == false){
            start = NULL;
            ragged = NULL;

            tam = new int[rows];
            matriz = new T*[rows];
            for(int i=0;i<rows;i++){
                tam[i] = arrayCol[i];
                matriz[i] = new T[tam[i]];
            }
        } else {
            tam = NULL;
            matriz = NULL;

            start = new int[rows+1];
            start[0] =  0;
            start[rows] = size;
            ragged = new T[size+1];
            for(int i = 0, j = 1; j<=rows; i++,j++){
                start[j] = start[i] + arrayCol[i];
            }
        }
    }

//N = número de linhas; R = tamanho das linhas
// O(N*R) para Tradicional
// O(N) para ragged
    template<class T>
    const MyMatrix<T> &MyMatrix<T>::operator=(const MyMatrix<T> &other){
        if(this==&other) return *this;
        rows = other.rows;
        size = other.size;
        
        if(!other.isRagged()){
            start = NULL;
            ragged = NULL;
            delete[] tam;
            for(int i=0;i<rows;i++)
                delete[] matriz[i];
            delete[] matriz;
            tam = new int[rows];

            for(int i=0;i<rows;i++) tam[i] = other.tam[i];
            matriz = new T*[rows];
            for(int i=0;i<rows;i++)
                matriz[i] = new T[tam[i]];
            for(int i=0;i<rows;i++)
                for(int j=0;j<tam[i];j++)
                    matriz[i][j] = other.matriz[i][j];
        } else {
            tam = NULL;
            matriz = NULL;
            delete[] ragged;
            delete[] start;
            

            start = new int[rows+1];
            ragged = new T[size+1];
            for(int i = 0; i<=rows; i++)
                start[i] = other.start[i];
            for(int i=0;i<size;i++) ragged[i] = other.ragged[i];
        }
        return *this;
    }

// Complexidade O(1)
    template<class T>
    MyMatrix<T>::MyMatrix(const MyMatrix<T> &other){
        rows = size = 0;
        start = NULL;
        ragged = NULL;
        tam = NULL;
        matriz = NULL;
        *this = other;
    }

// Complexidade O(1)
    template<class T>
    MyMatrix<T>::~MyMatrix(){
        if(!isRagged()){
            for(int i=0;i<rows;i++)
                delete[] matriz[i];
            delete[] matriz;
            delete[] tam;
        } else {
            delete[] ragged;
            delete[] start;
        }
        
        
    }

// ----------- ---------- //

// ----------- Funções GET/SET ---------- //

// Todas as funções abaixo tem Complexidade O(1)
    template<class T>
    void MyMatrix<T>::set(int linha, int coluna, const T&elem){
        if(!isRagged()){
            matriz[linha][coluna] = elem;
        } else {
            ragged[start[linha]+coluna] = elem;
        }
    }

    template<class T>
    const T &MyMatrix<T>::get(const int linha, const int coluna) const{
        if(!isRagged()){
            return matriz[linha][coluna];
        } else {
            return ragged[start[linha]+coluna];
        }
    }

    template<class T>
    int MyMatrix<T>::getNumCols(int linha) const{
        if(!isRagged()){
            return tam[linha];
        } else {
            return start[linha+1]-start[linha];
        }
    }

// ----------- ---------- //


// ----------- Funções Convert/isRagged ---------- //

//Complexidade O(3N*R)
// N = número de linhas; R = tamanho das linhas
    template<class T>
    void MyMatrix<T>::convertToRagged(){
        if(isRagged()){return;} // Verifica se não é ragged.
        else {start = new int[rows+1];
        start[0] =  0;
        start[rows] = size;
        ragged = new T[size+1];
        for(int i = 0, j = 1; j<rows; i++,j++){
            start[j] = start[i] + tam[i];
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<tam[i];j++){
                ragged[start[i]+j] = matriz[i][j];
            }
        }
        for(int i=0;i<rows;i++)
                delete[] matriz[i];
        delete[] matriz;
        delete[]tam;
        tam = NULL;
        matriz = NULL;
        }
    }

//Complexidade O(3N*R)
// N = número de linhas; R = tamanho das linhas
    template<class T>
    void MyMatrix<T>::convertToTraditional(){
        if(!isRagged()){return;}
        else{
            matriz = new T*[rows];
            tam = new int[rows];
            tam[rows-1] = start[rows] - start[rows-1];
            
            for(int i=rows-2, j=rows-3;i>=0;i--){
                tam[i] = start[i+1] - start[i];
            }  
        
            for(int i=0;i<rows;i++) matriz[i] = new T[tam[i]];
            for(int i=0;i<rows;i++){
                for(int j=0;j<tam[i];j++){
                    matriz[i][j] = ragged[start[i]+j];
                }
            }
            delete[]start;
            delete[]ragged;
            start = NULL;
            ragged = NULL;
        }  
    }

//Complexidade O(1)
    template<class T>
    bool MyMatrix<T>::isRagged() const{
        if(tam == NULL && matriz == NULL) {return true; }
        else{return false;}
    }

// ----------- ---------- //


// ----------- Função print ---------- //

//Complexidade O(2N*R)
// N = número de linhas; R = tamanho das linhas
    template<class T>
    void MyMatrix<T>::print() const{
        cout << "Rows: " << rows << endl;
        cout << "Elems: " << size << endl;
        if(!isRagged()){ 
            for(int i=0;i<rows;i++){
                if(i>0){
                    cout << endl;
                }
                if(tam[i] == 0)
                    cout << tam[i] << ":";
                for(int j=0;j<tam[i];j++){
                    if(j==0) cout << tam[i] << ": ";
                    
                    if(j+1==tam[i]) 
                        cout << matriz[i][j];
                    else cout << matriz[i][j] << " ";
                }
            }
            cout << endl;
        } else {
            // ----- Essa parte do código pegará as diferenças entre o vetor start para auxilar nos limites de cada linha -----//
                int *difStart = new int[rows];
                int *aux = new int[rows];
                for(int j=0, i=rows;i>0;j++,i--)
                    aux[j] = start[i]- start[i-1];
                for(int j=0, i=rows-1;i>=0;j++,i--)
                    difStart[j] = aux[i];
                delete[] aux;
            // ----- ----- //

            for(int i=0;i<rows;i++){
                if(i>0){
                    cout << endl;
                }
                if(difStart[i] == 0)
                    cout << difStart[i] << ":";
                for(int j=0;j<difStart[i];j++){
                    if(j==0) cout << difStart[i] << ": ";
                    
                    if(j+1==difStart[i]) 
                        cout << ragged[start[i]+j];
                    else cout <<  ragged[start[i]+j] << " ";
                }
            }
            delete[] difStart;
            cout << endl;
        }
    }

// ----------- ---------- //

// ----------- Funções resize ---------- //
// --- Para Tradicional --- //
//Complexidade O(N*R)
// N = número da nova linha; R = tamanho da nova linha

// --- Para Ragged --- //
//Complexidade O(4N*2C*2N)
// N = número de linhas; R = tamanho das linhas; C = tamanho da ragged
    template<class T>
    void MyMatrix<T>::resizeRow(int linha, int newSizeCol){
        if(!isRagged()){ // Tradicional
            T* aux = new T[tam[linha]];
            for(int i=0;i<tam[linha];i++){
            aux[i] = matriz[linha][i]; 
            }
            delete[] matriz[linha];
            matriz[linha] = new T[newSizeCol];
            for(int i=0;i<newSizeCol;i++){
                if(i>=tam[linha]){
                    matriz[linha][i] = 0;
                }else{
                    matriz[linha][i] = aux[i];
                }
            }
            delete[] aux;
            size += newSizeCol - tam[linha]; 
            tam[linha] = newSizeCol;
            
        } else { // Ragged
            // ----- Essa parte do código pegará as diferenças entre o vetor start para auxilar nos limites de cada linha -----//
                int *difStart = new int[rows];
                int *aux = new int[rows];
                for(int j=0, i=rows;i>0;j++,i--)
                    aux[j] = start[i]- start[i-1];
                for(int j=0, i=rows-1;i>=0;j++,i--)
                    difStart[j] = aux[i];
                delete[] aux;
            // ----- ----- //

            // ----- Essa parte do código conta quantos elementos tem até a linha que será inserida
            // ----- com o objetivo de auxilar a inserção no indice certo do vetor ragged ----- //
            int cont =0;
            for(int i=0;i<linha;i++)
                cont += difStart[i];
            // ----- ----- //

            if(newSizeCol>difStart[linha]){ //aumenta
                int cont2 = 0; // conta quantos elementos foram inseridos na linha a ser redimensionada 
                int cont3=0; //se for =1 é pq foi adicionado elemento em uma linha que continha 0
                int newSize = (newSizeCol-difStart[linha]) + size;
                T* auxRagged = new T[newSize];

                if(difStart[linha]==0){ // auxilia na organização dos índices
                    size++; rows++;
                }

                for(int i=0;i<size;i++){
                    if(i<cont) { // preenche antes de achar o índice
                        auxRagged[i] = ragged[i];
                    }else if(i==cont){ // preenche quando acha o índice, caso o j seja maior que a coluna antiga, preenche com valor padrão
                        for(int j=0;j<newSizeCol;j++){
                            if(j>=difStart[linha]){
                                auxRagged[i+j] = T();            
                            }else{
                                auxRagged[i+j]= ragged[j+i];                          
                                cont2++; //contando repetidos
                            } 
                        }
                    }else{ //preenche depois de achar o índice com um caso especial para caso a linha não tenha elementos
                        if(difStart[linha]==0){
                            auxRagged[i+newSizeCol-1] = ragged[i-1];
                            cont3++;
                        }else { // caso especial para caso seja a primeira linha
                            if(linha==0){
                                auxRagged[i+newSizeCol-cont2] = ragged[i+cont2-1];                
                            }else{
                                auxRagged[i+newSizeCol+2-cont2] = ragged[i+cont2-1];
                            }
                        }
                    }
                }

                if(difStart[linha]==0){
                    size--; rows--;
                }
            
                // ----- Realocação ----- //
                    delete[] ragged;
                    ragged = new T[newSize];
                    size = newSize;
                    for(int i=0;i<newSize;i++)
                        ragged[i] = auxRagged[i];
                    delete[] auxRagged;
                // ----- ----- //
                
                // ----- Essa parte do código organiza o vetor start devido as alocações feitas anteriormente ----- //
                    if(cont<=1){
                        for(int i=cont;i<=rows;i++){
                            if(i>cont){
                                start[i] = ((newSizeCol - difStart[linha]) + start[i]);
                            }
                        }
                    }
                    else if(difStart[linha]!=0){
                        for(int i=cont;i<=rows;i++){
                            if(i>=cont){
                                start[i] = ((newSizeCol - difStart[linha]) + start[i]);
                            }
                        }
                    }
                // ----- ----- //
                
                delete[] difStart;

            } else { //diminui (variáveis e condições similares à anterior)
                int cont2 = 0; // que conta a repetição
                int newSize = size - (difStart[linha]-newSizeCol) ;
                T* auxRagged = new T[newSize];
                
                for(int i=0;i<size;i++){
                    if(i<cont) {
                        auxRagged[i] = ragged[i];

                    }else if(i==cont && linha!=0){
                        if(difStart[linha]==0){ // faz nada
                            continue;
                        } else {
                            for(int j=0;j<newSizeCol;j++){
                                auxRagged[i+j]= ragged[j+i];                          
                                cont2++;
                            }
                        } 
                    }
                    else{
                        if((i-1+cont2)<0){
                            auxRagged[newSize] = ragged[size];
                        }else{
                            auxRagged[i-1+cont2] = ragged[i+cont2];
                        }
                    }
                }
                
                // ----- Realocação ----- //
                    delete[] ragged;
                    ragged = new T[newSize];
                    size = newSize;
                    for(int i=0;i<newSize;i++)
                        ragged[i] = auxRagged[i];
                    delete[] auxRagged;
                // ----- ----- //

            // ----- Essa parte do código organiza o vetor start devido as alocações feitas anteriormente ----- //
                if(cont<=1){
                        for(int i=cont;i<=rows;i++){
                            //cout << "esse é o valor que tinha: " << start[i] << " esse é que eu quero colcoar: " << (newSizeCol - difStart[linha]) + start[i] << endl;
                            if(i>cont){
                                start[i] = start[i]-((difStart[linha]- newSizeCol));
                            }
                        }
                    }
                    else {
                        for(int i=cont;i<=rows;i++){
                            //cout << "esse é o valor que tinha: " << start[i] << " esse é que eu quero colcoar: " << (newSizeCol - difStart[linha]) + start[i] << endl;
                            if(i>=cont){
                                start[i] = start[i]-((difStart[linha]- newSizeCol));
                            }
                        }
                    }
                // ----- ----- //

                delete[] difStart;
            }
        }
    }


    template<class T>
    void MyMatrix<T>::resizeNumRows(int newSizeRow){
// --- Para Tradicional --- //
//Complexidade O(N*R)
// N = número da nova linha; R = tamanho da nova linha

// --- Para Ragged --- //
//Complexidade O(4N*2C*2N)
// N = número de linhas; R = tamanho das linhas; C = tamanho da ragged

    // ----- Se torna intuitivo a alocação de linhas para a matriz tradicional.
    // ----- basicamente o que foi feito foi guardar valores antigos e dependendo do novo tamanho da linha
    // ----- alocar devidamente.
        if(!isRagged()){ 
            size = 0;
            int oldRow = rows;
            rows = newSizeRow;
            int *newTam = new int[rows];
            
            if(newSizeRow>oldRow){
                for(int i=0;i<rows;i++){
                    if(i>=oldRow){
                        newTam[i] = 0;
                    }else{
                        newTam[i] = tam[i];
                    }
                }
            }else{
                for(int i=0;i<rows;i++)
                    newTam[i] = tam[i];
            }

            delete[]tam;
            tam = new int[rows];
            if(newSizeRow>oldRow){
                for(int i=0;i<rows;i++){
                    if(i>=oldRow){
                        tam[i] = 0;
                    }else{
                        tam[i] = newTam[i];
                    }
                }
            }else{
                for(int i=0;i<rows;i++){
                    tam[i] = newTam[i];
                }
            }

            T** oldMatriz = new T*[oldRow];
            for(int i=0;i<oldRow;i++){
                if(i>=newSizeRow){
                    break;
                }
                oldMatriz[i] = new T[newTam[i]];
            }

            for(int i=0;i<rows;i++){
                for(int j=0;j<tam[i];j++){
                    oldMatriz[i][j] = matriz[i][j];
                }
            }

            for(int i=0;i<oldRow;i++){
                delete[] matriz[i];
            }
            delete[] matriz;

            matriz = new T*[rows];
            if(newSizeRow>oldRow){
                for(int i=0;i<rows;i++){
                        matriz[i] = new T[tam[i]];
                }
            }else{
                for(int i=0;i<rows;i++)

                    matriz[i] = new T[tam[i]];
            }
            
            if(newSizeRow>oldRow){
                for(int i=0;i<oldRow;i++){
                    for(int j=0;j<tam[i];j++){
                        matriz[i][j] = oldMatriz[i][j];
                        size++;
                    }
                }
            } else {
                for(int i=0;i<rows;i++){
                    for(int j=0;j<tam[i];j++){
                        matriz[i][j] = oldMatriz[i][j];
                        size++;
                    }
                }
            }

            for(int i=0;i<oldRow;i++){
                if(i>=newSizeRow){
                    break;
                }
                delete[] oldMatriz[i];
            }
            delete[] oldMatriz;
            delete[] newTam;

        } else { // Ragged
            int oldRow = rows;
            rows = newSizeRow;
            int *oldStart;
            T *oldRagged;
            oldStart = new int[oldRow+1];
            oldRagged = new T[size];
            for(int i=0;i<=oldRow;i++){
                oldStart[i] = start[i];
            }
            for(int i=0;i<size;i++){
                oldRagged[i] = ragged[i];
            }

            delete[] ragged;
            delete[] start;
            int auxSize =0;
            start = new int[rows+1];
            if(rows>oldRow){
                int difLinhas = rows - oldRow; 
                ragged = new T[size+difLinhas];
                // ----- Preenchendo start ----- //
                    for(int i=0;i<rows+1;i++){
                        if(i>oldRow)
                            start[i] = oldStart[oldRow]; // quando for maior preenche com o valor da ultima posição do start anterior
                        else 
                            start[i] = oldStart[i];
                    }
                // ----- ----- //

                // ----- Preenchendo ragged ----- //
                    for(int i=0;i<size+difLinhas;i++){
                        if(i>=size) 
                            ragged[i] = 0;
                        else {
                            ragged[i] = oldRagged[i];
                            auxSize++; //atualiza size
                        }
                    }
                // ----- ----- //
                size = auxSize;
            }else{

                for(int i=0;i<newSizeRow;i++){
                    start[i] = oldStart[i];
                } 
                size=0;
                ragged = new T[start[newSizeRow]];
            
                for(int i=0;i<start[newSizeRow];i++){
                    ragged[i] = oldRagged[i];
                    size++;
                }
            }
            delete[] oldStart;
            delete[] oldRagged;
        } 
    }
// ----------- ---------- //
#endif