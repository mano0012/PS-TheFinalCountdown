#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_

#include "View.cpp"
#include "Model.cpp"
#include <bits/stdc++.h>

using namespace std;

class Presenter{
    private:
        bool isLogged;
        int op;
        View *v;
        Model *m;
    public:
        Presenter();

        Presenter(string user, string pass);


        void start();

        /*TODO: Funçoes para cadastro de evento, remoção e buscas
        Na remoção, será pega a informação da view sobre qual evento remover
        Depois sera feita uma busca e então a remoção
        */
        bool menu();
};
#endif
