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

/*TODO: Funçoes para cadastro de evento, remoção e buscas
Na remoção, será pega a informação da view sobre qual evento remover
Depois sera feita uma busca e então a remoção
*/
