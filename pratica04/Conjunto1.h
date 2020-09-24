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
        Conjunto(int N);
        Conjunto();
        ~Conjunto();
        T &operator[](int i) { return c[i];  }
        bool pertence(const T &x) const;
        bool insere(const T &x); //return false quando full || repeat
        int numelementos() const{ return num_elementos; };
        bool operator==(const Conjunto<T>&x) const;
        Conjunto<T> &operator=(const Conjunto<T>&x);

    private:
        T *c;
        int num_elementos;
        int tamArray;
};


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
bool Conjunto<T>::pertence(const T &x) const {
    for(int i=0;i<tamArray;i++){
        if(c[i] == x){
            cout << "Item pertencente" << endl;
            return true;
        }
    }
    cout << "Item não pertencente" << endl;
    return false;
}


template<class T>
bool Conjunto<T>::insere(const T &x){
    if(num_elementos == tamArray ){
        cout << "não foi possível inserir, vetor cheio" << endl;
        return false;
    }
    if(pertence(x))
        return false;
    
    c[num_elementos] = x;
    num_elementos++;
    cout << "Inserido com sucesso" << endl;
    return true;
}


template<class T>
bool Conjunto<T>::operator==(const Conjunto<T>&x) const{
    for(int i=0;i<tamArray;i++){
        if(c[i] != x[i]){
            cout << "vetores diferentes" << endl;
            return false;
        }
    }
     cout << "vetores iguais" << endl;
     return true;
}


template<class T>
Conjunto<T> &Conjunto<T>::operator=(const Conjunto<T>&x){
    for(int i=0;i<tamArray;i++){
        c[i] = x[i];
    }
    return *this;
}

template<class T>
ostream & operator<<(ostream &os , const Conjunto<T> &v){
    for(int i=0;i<v.tamArray;i++){
        os << v[i] << " ";
    }
    return os;
}

template<class T>
istream & operator>>(istream & in, Conjunto<T> v){
    int numeroElementos, tamanhoArray;
    in >> tamanhoArray >> numeroElementos;
    v = new T(tamanhoArray);
    for(int i=0;i<numeroElementos;i++){
        in >> v[i];
    }

    return in;
}




#endif

