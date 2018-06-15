#include "Presenter.cpp"
#include "View.cpp"
#include <bits/stdc++.h>

//IMPLEMENTAR TUDO NO HPP PARA RESOLVER ERRO DE REFERENCIA

using namespace std;

//Utilizar Builder para criar evento
int main(int argc, char *argv[]){
    Presenter *p;
    View *v;

    v = new View;

    p = new Presenter;

    v->setPresenter(p);
    p->setView(v);


    p->start();
    /*if (argc==3){
        p = new Presenter(argv[1],argv[2]);
    } else p = new Presenter();*/




    return (0);
}
