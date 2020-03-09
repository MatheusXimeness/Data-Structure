#ifndef DATA_H
#define DATA_H

#include <iostream>

class Data {
  public:
    Data(int d=1, int m=1, int a=2017);
    Data(const Data &dt);
    void imprime();
    void setDia(int d);
    void setMes(int m);
    void setAno(int a);
    int getDia() const;
    int getMes() const;
    int getAno() const;
    int compData(Data dma);
    int difDias(Data dma);
  private:
    int dia, mes, ano;
};

// Forma alternativa de declarar e implementar a sobrecarga
// dos operadores >> e << sem usar funçoes friend
std::istream& operator>>(std::istream &in, Data &d);
std::ostream& operator<<(std::ostream &out, Data d);

#endif
