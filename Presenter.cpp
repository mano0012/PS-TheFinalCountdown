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
            int qtdEventos;
            evento = criaEvento();
            view->criaEvento(evento);

            //Refaz o arquivo de eventos
            qtdEventos = recuperaLista();
            inserirEvento(evento);
            qtdEventos++;

            gravaLista(qtdEventos);

            libera();

            view->changeView(MENU);
        }
};

class listaPresenter : public ContractListaPresenter {
    private:
        int numEvento;
        int id = 1;
        string nome;
        Data dataEvento;
        lista *temp;

    public:

        void setView(ContractListaView *v){
            view = v;
        }

        void start(){
            recuperaLista();
            lista *temp = listaEventos;

            if (temp!=NULL){
                switch(view->showMenu()){
                    case 1:
                        nome = view->buscaNome();
                        getByName(nome);
                        while(temp!=NULL){
                            if (temp->evento->isVisible()){
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
                                temp->evento->changeVisibility();
                                view->mostraEvento(temp->evento,id);
                            }
                            id++;
                            temp = temp->prox;
                        }
                    break;

                    case 3:
                        while(temp!=NULL){
                            view->mostraEvento(temp->evento,id);
                            id++;
                            temp = temp->prox;
                        }
                    break;
                }

                numEvento = view->selectEvents();
                if (numEvento != 0){
                    lista *temp = listaEventos;
                    for (int i=1;i<numEvento && temp!=NULL;i++) temp = temp->prox;

                    if (temp!=NULL) view->mostrarDetalhes(temp->evento);
                }

                libera();
            } else {
                view->noEvents();
            }

            view->changeView(MENU);
        }

};

#endif
