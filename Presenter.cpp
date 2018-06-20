#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_
#include "Contract.hpp"
#include "Model.cpp"

class menuPresenter : public ContractMenuPresenter{
    public:
        void start(){
            switch(view->showMenu()){
                case 0:
                    view->changeView("BYE");
                break;
                case 1:
                    view->changeView("Insere");
                break;
                case 2:
                    view->changeView("Lista");
                break;
            }
        }

        void setView(ContractMenuView *v){
            view = v;
        }
};

class inserePresenter : public ContractInserePresenter{
    public:

        void setView(ContractInsereView *v){
            view = v;
        }

        void start(){
            cout << "Criado: " << view->criaEvento() << endl;
        }
};

#endif
