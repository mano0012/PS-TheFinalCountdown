#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_
#include "Contract.hpp"
#include "Model.cpp"

class menuPresenter : public ContractMenu::Presenter{
    public:
        void start(){
            switch(view->showMenu()){
                case 0:
                    view->change("BYE");
                break;
                case 1:
                    view->change("Insere");
                break;
                case 2:
                    view->change("Lista");
                break;
            }
        }

        void setView(ContractMenu::View *v){
            view = v;
        }
};

class inserePresenter : public ContractInsere::Presenter{
    void setView(ContractInsere::View *v){
        view = v;
    }

    void start(){
        cout << "Criado: " << view->criaEvento() << endl;
    }

};

#endif
