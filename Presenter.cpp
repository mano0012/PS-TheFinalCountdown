#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_
#include "Contract.hpp"
//#include "Model.hpp"
class menuPresenter : public ContractMenuPresenter{
    public:
        void start(){
            switch(view->showMenu()){
                case 0:
                    libera();
                    view->endOfLife();
                break;
                case 1:
                    view->changeView(INSERE);
                break;
                case 2:
                    view->changeView(LISTAR);//Mudar qual classe
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
            inserirEvento(evento);
            view->changeView(MENU);
        }
};

class listaPresenter : public ContractListaPresenter {
    public:

        void setView(ContractListaView *v){
            view = v;
        }

        void start(){
            int numEvento;
            switch(view->showMenu()){
                case 1:
                    string nome;
                    nome = view->buscaNome();
                    numEvento = view->mostraListaEventos(getByName(nome));
                break;
                case 2:
                    Data dataEvento;
                    dataEvento = view->buscaData();
                    numEvento = view->mostraListaEventos(getByDate(dataEvento));
                break;
            }
        }

}

#endif
