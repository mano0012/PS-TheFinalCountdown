#include "Contract.hpp"
#include "Presenter.cpp"

//Fabrica que ir� criar as Views
class FactoryView{
    public:
        static ContractView * cria(classView opcao);
};

class menuView : public ContractMenuView {
    public:
        ContractMenuPresenter *presenter;

        void setPresenter(){
            presenter = new menuPresenter;
            presenter->setView(this);
            presenter->start();
        }

        int showMenu(){
            int op;
            cout << "========MENU========" << endl;
            cout << "1- Inserir Evento\n2- Listar Eventos\n0- Sair\nSelecione uma opcao: ";
            cin >> op;
            while (op<0 || op>2){
                cout << "Op��o invalida, digite novamente: ";
                cin >> op;
            }

            return op;
        }

        void changeView(classView option){
            ContractView *newView;
            delete presenter;

            newView = FactoryView::cria(option);
            newView->start(this);
        }

};

class insereView : public ContractInsereView{
    public:
        ContractInserePresenter *presenter;

        void setPresenter(){
            presenter = new inserePresenter;
            presenter->setView(this);
            presenter->start();
        }

        void criaEvento(Evento *evento){
            int data;
            cout << "Digite o nome do evento: ";
            cin >> evento->nome;
            cout << "Digite o local do evento: ";
            cin >> evento->local;
            cout << "Digite o dia de inicio do Evento: ";
            cin >> data;
            evento->dataInicio->setDia(data);
            cout << "Digite o mes de inicio do Evento: ";
            cin >> data;
            evento->dataInicio->setMes(data);
            cout << "Digite o ano de inicio do Evento: ";
            cin >> data;
            evento->dataInicio->setAno(data);

            cout << "Digite o dia de finaliza��o do Evento: ";
            cin >> data;
            evento->dataFim->setDia(data);
            cout << "Digite o mes de finaliza��o do Evento: ";
            cin >> data;
            evento->dataFim->setMes(data);
            cout << "Digite o ano de finaliza��o do Evento: ";
            cin >> data;
            evento->dataFim->setAno(data);

            evento->isVisible = false;

        }

        void changeView(classView option){
            ContractView *newView;
            delete presenter;

            newView = FactoryView::cria(option);
            newView->start(this);

        }
};

//Fun��o de cria��o
ContractView * FactoryView::cria(classView opcao){
    switch(opcao){
        case MENU:
            return new menuView;
        break;
        case INSERE:
            return new insereView;
        break;

        default:
            return NULL;
        break;
    /*if (opcao=="MENU") return new menuView;
    else if (opcao=="INSERE") return new insereView;
    else return NULL;*/
    }
}
