#include <bits/stdc++.h>
#include "View.cpp"
#include "Presenter.cpp"
using namespace std;

int main(int argc, char *argv[]){
    ContractMenuView *view;

    view = new menuView;

    if (view!=NULL){
        if (argc != 1 && argc != 3){
            view->showExecutionError(argv[0]);
            return (0);
        }

        if (argc == 3) autenticaUsuario(argv[1],argv[2]);

        view->start(NULL);
    }

    return (0);
}
