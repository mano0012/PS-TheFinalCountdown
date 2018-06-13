#include "Presenter.hpp"

Presenter::Presenter(){
    m = new Model();
    isLogged = false;
    v = new View();
}

Presenter::Presenter(string user, string pass){
    m = new Model();
    isLogged = m->autentica(user,pass);
    v = new View();
}


void Presenter::start(){
    while(menu());
}

/*TODO: Funçoes para cadastro de evento, remoção e buscas
Na remoção, será pega a informação da view sobre qual evento remover
Depois sera feita uma busca e então a remoção
*/
bool Presenter::menu(){
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
