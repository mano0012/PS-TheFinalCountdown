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

//Os eventos estarao ordenados por nome
void Model::inserirEventoArvore(Evento *e){

}
//Os eventos estarao ordenados por data
void Model::inserirEventoLista(Evento *e){

}
/*TODO: Funções para busca de evento, criar a lista de eventos(ou arvore vide a forma de busca)
Função para remover.
A função de busca irá sempre retornar o ondereço do registo, pois, caso seja para ser exibido,
o Presenter consegue repassar as informações para a view, e caso seja remoção, o presenter consiga
pedir ao model que remova o endereço.

Caso seja inserido um evento com uma data no passado, exibir erro
*/

bool Model::autentica(string u, string p){
    if (user == u && pass == p) return true;
    return false;
}
