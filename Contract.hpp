#ifndef CONTRACT_HPP_
#define CONTRACT_HPP_

#include "Model.cpp" //Caso de problema, criar o .o do Model
#include <bits/stdc++.h>

using namespace std;

typedef enum {
    MENU = 0,
    INSERE = 1,
    LISTAR = 2,
    REMOVER = 3
} classView;


//Funcoes comuns a todas as Views
class ContractView{
    public:
        virtual void changeView(classView option) = 0;

        virtual void setPresenter() = 0;

        void start(ContractView *last){
            if (last!=NULL) delete last;

            setPresenter();
        }

        //virtual void showExecutionError(string name) = 0;

        virtual void deletePresenter() = 0;
};
//Fim

//Contrato-Menu
class ContractMenuView : public ContractView{
    public:
            virtual int showAdminMenu() = 0;
            virtual int showMenu() = 0;
            virtual void endOfLife() = 0;
            virtual void showExecutionError(string name) = 0;
};

class ContractMenuPresenter{
            public:
                ContractMenuView *view;
                virtual void setView(ContractMenuView *v) = 0;
                virtual void start() = 0;
};
//Fim Contrato-Menu

//Contrato InserirEvento
class ContractInsereView : public ContractView{
    public:
        virtual void criaEvento(Evento *evento) = 0;

};

class ContractInserePresenter {
    public:
        ContractInsereView *view;
        Evento *evento;
        virtual void setView(ContractInsereView *v) = 0;
        virtual void start() = 0;
};
//Fim ContratoInserirEvento

//Inicio ContratoListarEventos
class ContractListaView : public ContractView {
    public:

        virtual void mostraEvento(Evento *evento, int id) = 0;

        virtual int showMenu() = 0;

        virtual void setRemover() = 0;

        virtual void mostrarDetalhes(Evento *evento) = 0;

        virtual string buscaNome() = 0;

        virtual Data buscaData() = 0;

        virtual int selectEvents() = 0;

        virtual  void noEvents() = 0;
};


class ContractListaPresenter {
    public:
        ContractListaView *view;

        virtual void setView(ContractListaView *v) = 0;

        virtual void start(bool remover) = 0;

};
//Fim ContratoListarEventos

class ContractRemoverView : public ContractView {
    public:
        ContractListaView *view;
        virtual void removerEvento() = 0;
        virtual void errorMessage() = 0;

};

class ContractRemoverPresenter {
    public:
        ContractRemoverView *view;

        virtual void setView(ContractRemoverView *v) = 0;

        virtual void start() = 0;

};

#endif
