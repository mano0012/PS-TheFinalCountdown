#include "Presenter.hpp"

void Presenter::setView(View *view){
    v = view;
}

void Presenter::start(){
    v->start(NULL);
}

void Presenter::teste(){
    cout << "DEU CARAI" << endl;
}

/*TODO: Fun�oes para cadastro de evento, remo��o e buscas
Na remo��o, ser� pega a informa��o da view sobre qual evento remover
Depois sera feita uma busca e ent�o a remo��o
*/
