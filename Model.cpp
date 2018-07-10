#include "Model.hpp"

void Data::setDia(int d){
    dia = d;
}

void Data::setMes(int m){
    mes = m;
}

void Data::setAno(int a){
    ano = a;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}

string Data::getData(){
    string d,m,a;

    d = dia + '0';
    m = mes + '0';
    a = ano + '0';

    d.insert(d.begin(), 2 - d.length(), '0');
    m.insert(m.begin(), 2 - m.length(), '0');

    return d + "/" + m + "/" + a;
}

Evento * criaEvento(){
    Evento *evento = new Evento;

    return evento;
}

void inserirEvento(Evento *evento){
    lista *aux = (lista *)malloc(sizeof(lista));
    lista *temp;
    bool inseriu = false;


    aux->ant = NULL;
    aux->prox = NULL;
    aux->evento = evento;

    if (listaEventos!=NULL){
        temp = listaEventos;

        if (temp->evento->dataInicio->getDia() > aux->evento->dataInicio->getDia()){
            aux->prox = temp;
            temp->ant = aux;
            listaEventos = aux;
        } else {
            while (!inseriu){
                if (temp->prox != NULL){
                    temp = temp->prox;

                    if (temp->evento->dataInicio->getDia() > aux->evento->dataInicio->getDia()){
                        aux->prox = temp;
                        aux->ant = temp->ant;
                        temp->ant->prox = aux;
                        temp->ant = aux;
                        inseriu = true;
                    }
                } else {
                    temp->prox = aux;
                    aux->ant = temp;
                    inseriu = true;
                }
            }

        }
    } else {
        listaEventos = aux;
    }
}

void gravaLista(){
    FILE *arq;
    lista *temp = listaEventos;

    arq = fopen("Eventos.txt","wb");

    while (temp!=NULL){
        fwrite(temp->evento,sizeof(Evento),1,arq);
        temp = temp->prox;
    }
}

void recuperaLista(){
    FILE *arq;
    Evento *evento = new Evento;

    arq = fopen("Eventos.txt","rb");

    if (arq!=NULL){
        while (!feof(arq)){
            fread(evento,sizeof(Evento),1,arq);
            inserirEvento(evento);
        }
    }
}

void libera(){
    lista *temp;

    temp = listaEventos;

    while (listaEventos!=NULL){
        listaEventos = listaEventos->prox;
        free (temp);
        temp = listaEventos;
    }

    temp = listaBusca;

    while (listaBusca != NULL){
        listaBusca = listaBusca->prox;
        free (temp);
        temp = listaBusca;
    }
}

/*TODO: Fun��es para busca de evento, criar a lista de eventos(ou arvore vide a forma de busca)
Fun��o para remover.
A fun��o de busca ir� sempre retornar o ondere�o do registo, pois, caso seja para ser exibido,
o Presenter consegue repassar as informa��es para a view, e caso seja remo��o, o presenter consiga
pedir ao model que remova o endere�o.

Caso seja inserido um evento com uma data no passado, exibir erro
*/

