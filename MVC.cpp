#include <bits/stdc++.h>

using namespace std;

class Data{
    private:
        int dia;
        int mes;
        int ano;
    public:

        void setDia(int d){
            dia = d;
        }

        void setMes(int m){
            mes = m;
        }

        void setAno(int a){
            ano = a;
        }

        int getDia(){
            return dia;
        }

        int getMes(){
            return mes;
        }

        int getAno(){
            return ano;
        }

        string getData(){
            string d,m,a;

            d = dia + '0';
            m = mes + '0';
            a = ano + '0';

            d.insert(d.begin(), 2 - d.length(), '0');
            m.insert(m.begin(), 2 - m.length(), '0');

            return d + "/" + m + "/" + a;
        }
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
        void inserirEventoArvore(Evento *e){
            no *aux = (no *) malloc(sizeof(no));

            aux->e = e;
            aux->dir = NULL;
            aux->esq = NULL;

            if (arvore!=NULL){


            } else arvore = aux;
        }

        //Os eventos estarao ordenados por data
        void inserirEventoLista(Evento *e){


        }
        /*TODO: Funções para busca de evento, criar a lista de eventos(ou arvore vide a forma de busca)
        Função para remover.
        A função de busca irá sempre retornar o ondereço do registo, pois, caso seja para ser exibido,
        o Presenter consegue repassar as informações para a view, e caso seja remoção, o presenter consiga
        pedir ao model que remova o endereço.

        Caso seja inserido um evento com uma data no passado, exibir erro
        */

        bool autentica(string u, string p){
            if (user == u && pass == p) return true;
            return false;
        }


};

class View{
    public:
        int showMenu(){
            int op;
            cout << "=======Menu=======" << endl;
            cout << "1- Listar eventos\n2- Procurar evento\n0- Sair" << endl;
            cout << "Selecione a opcao: ";
            cin >> op;
            while(op<0 || op>2){
                cout << "Opcao invalida, digite novamente: ";
                cin >> op;
            }
            return op;
        }

        int showMenuAdmin(){
            int op;
            cout << "=======Menu=======" << endl;
            cout << "1- Listar eventos\n2- Procurar evento\n3- Cadastrar evento\n4- Remover evento\n5- Alterar evento\n0- Sair" << endl;
            cout << "Selecione a opcao: ";
            cin >> op;
            while(op<0 || op>2){
                cout << "Opcao invalida, digite novamente: ";
                cin >> op;
            }
            return op;
        }

        /*TODO: View para cadastro de evento e remoção de evento
        View para busca de evento e listarEvento
        */

        void bye(){
            cout << "Obrigado por utilizar o programa" << endl;
        }


};

class Presenter{
    private:
        bool isLogged;
        int op;
        View *v;
        Model *m;
    public:
        Presenter(){
            v = new View;
            m = new Model();
            isLogged = false;
        }

        void autenticar(string user, string pass){
            isLogged = m->autentica(user,pass);
        }


        /*TODO: Funçoes para cadastro de evento, remoção e buscas
        Na remoção, será pega a informação da view sobre qual evento remover
        Depois sera feita uma busca e então a remoção
        */
        bool menu(){
            if(!isLogged) op = v->showMenu();
            else op = v->showMenuAdmin();

            switch(op){
                case 0:
                    v->bye();
                    return false;
                break;
            }

            return true;
        }

};

//Utilizar Builder para criar evento
int main(int argc, char *argv[]){
    Presenter *p = new Presenter();

    if (argc!=1 && argc!=3){
        cout << "Sintaxe: ./Programa ou ./Programa login senha" << endl;
        return (0);
    }

    if (argc==3){
            p->autenticar(argv[1],argv[2]);
    }

    while(p->menu());

    return (0);
}
