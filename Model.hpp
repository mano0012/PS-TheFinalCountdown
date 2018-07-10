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
};


//isVisible é setado para true somente quando ele será mostrado, ou seja, quando uma pesquisa é feita
//Isso é para poder mostrar os eventos em uma determinada data em ordem alfabetica
//Ou eventos com um determinado nome em ordem de data
class Evento{
    public:
        string nome;
        string local;
        string desc;
        Data *dataInicio;
        Data *dataFim;
        bool isVisible;

        Evento(){
            dataInicio = new Data;
            dataFim = new Data;
        }

        /*void setNome(string nome){
            this.nome = nome;
        }*/

        //Terminar o evento

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
lista *listaBusca = NULL;
//Para armazenar de acordo com a data, utilizar apenas uma lista
//Para armazenar de acordo com o nome, utilizar Árvore
/*A arvore ajudará a dar o resultado em ordem alfabetica e o usuario nao precisará
digitar o nome todo para encontrar o evento*/

void libera();


#endif
