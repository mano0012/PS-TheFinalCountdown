#include "Presenter.cpp"
#include <bits/stdc++.h>

//IMPLEMENTAR TUDO NO HPP PARA RESOLVER ERRO DE REFERENCIA

using namespace std;

//Utilizar Builder para criar evento
int main(int argc, char *argv[]){
    Presenter *p;

    if (argc==3){
        p = new Presenter(argv[1],argv[2]);
    } else p = new Presenter();

    p->start();



    return (0);
}
