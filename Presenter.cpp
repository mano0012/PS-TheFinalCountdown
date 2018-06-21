#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_
#include "Contract.hpp"
//#include "Model.hpp"
class menuPresenter : public ContractMenuPresenter{
    public:
        void start(){
            switch(view->showMenu()){
                case 0:
                    view->changeView(MENU);//Mudar qual classe
                break;
                case 1:
                    view->changeView(INSERE);
                break;
                case 2:
                    view->changeView(MENU);//Mudar qual classe
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
            evento = criaEvento();
            view->criaEvento(evento);
            inserirEventoData(evento);
            view->changeView(MENU);
        }
};

#endif
