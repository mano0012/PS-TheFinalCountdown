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
    private:
        int id;
        string nome;
        string local;
        Data *dataInicio;
        Data *dataFim;
        bool isVisible;
    public:

        //Terminar o evento

};

typedef struct a {
    Evento *e;
    struct a *dir;
    struct a *esq;
} no;

typedef struct b {
    Evento *e;
    struct b *prox;
    struct b *ant;
} lista;

//Para armazenar de acordo com a data, utilizar apenas uma lista
//Para armazenar de acordo com o nome, utilizar Árvore
/*A arvore ajudará a dar o resultado em ordem alfabetica e o usuario nao precisará
digitar o nome todo para encontrar o evento*/

class Model{
    private:
        string user;
        string pass;
        no *arvore;
        lista *l;
    public:
        Model(){
            user = "admin";
            pass = "admin";
            arvore = NULL;
            l = NULL;
        }

        //Os eventos estarao ordenados por nome
        void inserirEventoArvore(Evento *e);
        //Os eventos estarao ordenados por data
        void inserirEventoLista(Evento *e);
        /*TODO: Funções para busca de evento, criar a lista de eventos(ou arvore vide a forma de busca)
        Função para remover.
        A função de busca irá sempre retornar o ondereço do registo, pois, caso seja para ser exibido,
        o Presenter consegue repassar as informações para a view, e caso seja remoção, o presenter consiga
        pedir ao model que remova o endereço.

        Caso seja inserido um evento com uma data no passado, exibir erro
        */

        bool autentica(string u, string p);
};

#endif
