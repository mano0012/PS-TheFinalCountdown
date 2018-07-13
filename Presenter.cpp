#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_
#include "Contract.hpp"

class menuPresenter : public ContractMenuPresenter{
    public:
        void start(){
            if (autenticado){
                switch(view->showAdminMenu()){
                    case 0:
                        view->endOfLife();
                    break;
                    case 1:
                        view->changeView(INSERE);
                    break;
                    case 2:
                        view->changeView(LISTAR);
                    break;
                    case 3:
                        view->changeView(REMOVER);
                    break;
                }
            } else {
                switch(view->showMenu()){
                    case 0:
                        view->endOfLife();
                    break;
                    case 1:
                        view->changeView(LISTAR);
                    break;
                }
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

            recuperaLista();
            inserirEvento(evento);

            incQtdEventos();

            gravaLista();

            liberaLista();

            view->changeView(MENU);
        }
};

class listaPresenter : public ContractListaPresenter {
    private:
        int numEvento;
        int id;
        string nome;
        Data dataEvento;
        lista *temp;

    public:
        listaPresenter(){
            id = 1;
        }
        void setView(ContractListaView *v){
            view = v;
        }

        void start(bool remover){
            bool mostrouEvento = false;
            recuperaLista();
            lista *temp = listaEventos;

            if (temp!=NULL){
                switch(view->showMenu()){
                    case 1:
                        nome = view->buscaNome();
                        getByName(nome);
                        while(temp!=NULL){
                            if (temp->evento->isVisible()){
                                mostrouEvento = true;
                                temp->evento->changeVisibility();
                                view->mostraEvento(temp->evento,id);
                            }
                            id++;
                            temp = temp->prox;
                        }
                    break;

                    case 2:
                        dataEvento = view->buscaData();
                        getByDate(dataEvento);

                        while(temp!=NULL){
                            if (temp->evento->isVisible()){
                                mostrouEvento = true;
                                temp->evento->changeVisibility();
                                view->mostraEvento(temp->evento,id);
                            }
                            id++;
                            temp = temp->prox;
                        }
                    break;
                    case 3:
                        mostrouEvento = true;
                        while(temp!=NULL){
                            view->mostraEvento(temp->evento,id);
                            id++;
                            temp = temp->prox;
                        }
                    break;
                }

                if(mostrouEvento){
                    numEvento = view->selectEvents();

                    if (numEvento != 0){
                        lista *temp = listaEventos;
                        for (int i=1;i<numEvento && temp!=NULL;i++) temp = temp->prox;

                        if (temp!=NULL){
                            if (!remover){
                                view->mostrarDetalhes(temp->evento);
                            } else {
                                eventoRemover = temp;
                                return;
                            }
                        }
                    }
                } else view->noEvents();
            } else view->noEvents();

            liberaLista();

            view->changeView(MENU);
        }

};

class removerPresenter : public ContractRemoverPresenter{
    public:
        void setView(ContractRemoverView *v){
            view = v;
        }

        void start(){
            view->removerEvento();

            if(eventoRemover!=NULL){
                removeEvent();
                decQtdEventos();
                gravaLista();
            } else {
                view->errorMessage();
            }

            liberaLista();
            view->changeView(MENU);
        }
};

#endif
