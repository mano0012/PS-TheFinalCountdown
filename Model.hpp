#ifndef MODEL_HPP_
#define MODEL_HPP_

#include <bits/stdc++.h>

using namespace std;

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:

        void setDia(int d);

        void setMes(int m);

        void setAno(int a);

        int getDia();

        int getMes();

        int getAno();

        string getData();

        void setCampos(string data);
};


class Evento{
    private:
        string nome;
        string local;
        string desc;
    public:
        Data *dataInicio;
        Data *dataFim;
        bool visible;

        Evento(){
            dataInicio = new Data;
            dataFim = new Data;
        }

        void setNome(string name){
            nome = name;
        }

        void setLocal(string place){
            local = place;
        }

        void setDesc(string descricao){
            desc = descricao;
        }

        string getNome(){
            return nome;
        }

        string getLocal(){
            return local;
        }

        string getDesc(){
            return desc;
        }

        bool isVisible(){
            return visible;
        }

        void changeVisibility(){
            visible = !visible;
        }

};

typedef struct a {
    Evento *e;
    struct a *dir;
    struct a *esq;
} no;

typedef struct b {
    Evento *evento;
    struct b *prox;
    struct b *ant;
} lista;

lista *listaEventos = NULL;
lista *eventoRemover = NULL;
bool autenticado = false;
bool inverse = false;

int tamanhoLista = 0;

void liberaLista();


#endif
