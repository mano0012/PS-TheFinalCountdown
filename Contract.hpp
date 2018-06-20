#ifndef CONTRACT_HPP_
#define CONTRACT_HPP_

#include <bits/stdc++.h>

using namespace std;

//Funcoes comuns a todas as Views
class ContractView{
    public:
        virtual void changeView(string option) = 0;
        virtual void start(ContractView *last) = 0;
        virtual void setPresenter() = 0;
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
        virtual int criaEvento() = 0; //Utilizar Builder

};

class ContractInserePresenter {
    public:
        ContractInsereView *view;
        virtual void setView(ContractInsereView *v) = 0;
        virtual void start() = 0;
};
//Fim ContratoInserirEvento

#endif
