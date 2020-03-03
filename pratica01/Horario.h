#ifndef HORARIO_H
#define HORARIO_H

class Horario {
    public:

        Horario(int h =0, int m =0, int s =0);
        Horario(const Horario&);

        void setHora(int h);
        void setMinuto(int m);
        void setSegundo(int s);

        int getHora() const;
        int getMinuto() const;
        int getSegundo() const;

        int compHorario(const Horario&);
        int difSegundos(const Horario&);

        void imprime();

    private:
    
        int hora;
        int minuto;
        int segundo;
        
};
