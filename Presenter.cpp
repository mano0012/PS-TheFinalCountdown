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

/*TODO: Fun�oes para cadastro de evento, remo��o e buscas
Na remo��o, ser� pega a informa��o da view sobre qual evento remover
Depois sera feita uma busca e ent�o a remo��o
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
