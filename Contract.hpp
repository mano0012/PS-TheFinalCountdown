#ifndef CONTRACT_HPP_
#define CONTRACT_HPP_

#include "Model.cpp" //Caso de problema, criar o .o do Model
#include <bits/stdc++.h>

using namespace std;

typedef enum {
    MENU = 0,
    INSERE = 1
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
};
//Fim

//Contrato-Menu
class ContractMenuView : public ContractView{
    public:
        public:
                virtual int showMenu() = 0;
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
        virtual void criaEvento(Evento *evento) = 0; //Utilizar Builder

};

class ContractInserePresenter {
    public:
        ContractInsereView *view;
        Evento *evento;
        virtual void setView(ContractInsereView *v) = 0;
        virtual void start() = 0;
};
//Fim ContratoInserirEvento

//Contrato BuscarEvento
class ContractBuscaView : public ContractView {
    public:
        int mostraMenu();

        Data * buscaEventoData();

        string buscaEventoNome();

};

class ContractBuscaPresenter {
    public:
        ContractBuscaView *view;

        virtual void setView(ContractBuscaView *v) = 0;

        virtual void start() = 0;

        virtual void buscaData(Data *data);

        virtual void buscaNome(string nome);
};


//Contrato MostrarEvento
/*class ContractMostraEvento : public ContractView{
    public:


};*/





#endif
