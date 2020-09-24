#ifndef CONJUNTO1_H
#define CONJUNTO1_H
#include<iostream>
#include<istream>
#include<ostream>
using namespace std;


template<class T>
class Conjunto;

template<class T>
ostream & operator<<(ostream &, const Conjunto<T> &);
template<class T>
istream & operator>>(istream &, Conjunto<T>&);


template<class T>
class Conjunto{

    friend ostream & operator<< <T>(ostream &, const Conjunto<T> &);
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
        const Conjunto &operator=(const Conjunto<T>&);
        void le( Conjunto<T>);
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
    } else {
    // fazendo atribuição
        tamArray = other.tamArray;
        c = new T[tamArray];
        num_elementos = other.num_elementos;
        for(int i=0; i<tamArray; i++) c[i] = other.c[i];    
    }
}


template<class T>
Conjunto<T>::Conjunto(int N){
    cout << "construindo com args" << endl;
    c = new T[N];
    num_elementos = 0;
    tamArray = N;
}


template<class T>
Conjunto<T>::Conjunto(){
    cout << "construindo sem args" << endl;
    num_elementos = 0;
    tamArray = 10;
    c = new T[tamArray];
}


template<class T>
Conjunto<T>::~Conjunto(){
    delete[] c;
}


template<class T>
bool Conjunto<T>::pertence(const T &elem) const {
    for(int i=0;i<tamArray;i++){
        if(c[i] == elem){
            return true;
        }
    }
    return false;
}


template<class T>
bool Conjunto<T>::insere(const T &elem){
    if(num_elementos == tamArray || pertence(elem) ){
        return false;
    }
    c[num_elementos] = elem;
    num_elementos++;
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
const Conjunto<T> &Conjunto<T>::operator=(const Conjunto<T>&other){
    // testando auto atribuição
    if(&other == this){
        return *this;
    }
    // fazendo atribuição
    delete []c;
    tamArray = other.tamArray;
    num_elementos = other.num_elementos;
    c = new T[tamArray];
    for(int i=0; i<tamArray; i++) c[i] = other.c[i];    
    return *this;
}


template<class T>
void Conjunto<T>::imprime() const {
    cout << "{";
    for(int i=0; i<num_elementos-1; i++) cout << c[i] << ", ";
    cout << c[num_elementos-1]<< "}"<< endl;
}

template<class T>
ostream & operator<<(ostream &os , const Conjunto<T> &v){
    v.imprime();

    return os;
}

template<class T>
void Conjunto<T>::le(Conjunto<T> v) {
	  for(int i=0; i<v.tamArray; i++){
            cin >> v.c[i];
            insere(v.c[i]);
      }									
}

template<class T>
std::istream & operator>>(std::istream & in, Conjunto<T>& v){
    v.le(v);
    return in;
}




#endif

