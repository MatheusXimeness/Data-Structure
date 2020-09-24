#ifndef CONJUNTO1_H
#define CONJUNTO1_H
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;


template<class T>
class Conjunto;

template<class T>
ostream & operator<<(ostream &, const Conjunto<T> &v);
template<class T>
istream & operator>>(istream &, Conjunto<T>&v);


template<class T>
class Conjunto{

    friend ostream & operator<< <T>(ostream &, const Conjunto<T> &v);
    friend istream & operator>> <T>(istream &, Conjunto<T>&);

    public:
        Conjunto(const Conjunto<T> &);
        Conjunto(int N);
        Conjunto();
        ~Conjunto();
        // T &operator[](int i) { return c[i]; } talvez
        bool pertence(const T &) const;
        bool insere(const T &); //return false quando full || repeat
        int numelementos() const{ return num_elementos; };
        bool operator==(const Conjunto<T>&) const;
        Conjunto<T> &operator=(const Conjunto<T>&);
        void le();
        void imprime() const;

    private:
        T *c;
        int num_elementos;
        int tamArray;
};


template<class T>
Conjunto<T>::Conjunto(const Conjunto<T> &other){
    // testando auto atribuição
    if(this == &other){
        return *this;
    } else {
    // fazendo atribuição
        delete []c;
        c = new T(other.tamArray);
        num_elementos = other.num_elementos;
        for(int i=0; i<tamArray; i++) c[i] = other.c[i];    
        return *this;
    }
}


template<class T>
Conjunto<T>::Conjunto(int N){
    cout << "construindo com args" << endl;
    c = new T(N);
    num_elementos = 0;
    tamArray = N;
    for(int i=0; i<N; i++){
        c[i] = T();
    }
}


template<class T>
Conjunto<T>::Conjunto(){
    cout << "construindo sem args" << endl;
    num_elementos = 0;
    tamArray = 10;
    c = new T(tamArray);
}


template<class T>
Conjunto<T>::~Conjunto(){
    cout << "destruindo" << endl;
    delete[] c;
}


template<class T>
bool Conjunto<T>::pertence(const T &elem) const {
    for(int i=0;i<tamArray;i++){
        if(c[i] == elem){
            cout << "Item pertencente" << endl;
            return true;
        }
    }
    cout << "Item não pertencente" << endl;
    return false;
}


template<class T>
bool Conjunto<T>::insere(const T &elem){
    if(num_elementos == tamArray || pertence(elem) ){
        cout << "não foi possível inserir, vetor cheio" << endl;
        return false;
    }
    c[num_elementos] = elem;
    num_elementos++;
    cout << "Inserido com sucesso" << endl;
    return true;
}


template<class T>
bool Conjunto<T>::operator==(const Conjunto<T>&other) const{
    if(tamArray != other.tamArray)
        return false;
    for(int i=0;i<tamArray;i++)
        if(!pertence(other.c[i]))
            return false;
    return true;
}


template<class T>
Conjunto<T> &Conjunto<T>::operator=(const Conjunto<T>&other){
    // testando auto atribuição
    if(this == &other){
        return *this;
    } else {
    // fazendo atribuição
        delete []c;
        c = new T(other.tamArray);
        num_elementos = other.num_elementos;
        for(int i=0; i<tamArray; i++) c[i] = other.c[i];    
        return *this;
    }
}


template<class T>
void Conjunto<T>::imprime() const {
    cout << "Número de elementos: " << num_elementos << endl;
    cout << "Tamanho do array: " << tamArray << endl;
    for(int i=0; i<tamArray; i++) cout << c[i] << " ";
    cout << endl;
}

template<class T>
ostream & operator<<(ostream &os , const Conjunto<T> &v){
    v.imprime();

    return os;
}

template<class T>
void Conjunto<T>::le() {
    int numElem =0;
    int tamanho;
    cout << "Digite o tamanho do seu vetor" << endl;
    cin >> tamanho;
    T *conj = new T[tamanho];
    for(int i=0;i<tamanho;i++){
        cin >> conj[i];
        numElem++; 
    }
}


template<class T>
istream & operator>>(istream & in, Conjunto<T> v){
    v.le();
    return in;
}




#endif

