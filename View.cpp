#include "Contract.hpp"
#include "Presenter.cpp"

//Fabrica que ir� criar as Views
class FactoryView{
    public:
        static ContractView * cria(string opcao);
};

class menuView : public ContractMenuView {
    public:
        ContractMenuPresenter *presenter;
        void start(ContractView *last){
            if (last!=NULL) delete last;
            setPresenter();
        }


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

        void changeView(string option){
            ContractView *newView;
            delete presenter;

            newView = FactoryView::cria("INSERE");
            newView->start(this);
        }

};

class insereView : public ContractInsereView{
    public:
        ContractInserePresenter *presenter;
        void start(ContractView *last){
            delete last;
            setPresenter();
        }

        void setPresenter(){
            presenter = new inserePresenter;
            presenter->setView(this);
            presenter->start();
        }

        int criaEvento(){
            cout << "Evento ";
            return 0;
        }

        void changeView(string option){
            cout << "Nao implementado" << endl;
        }
};

//Fun��o de cria��o
ContractView * FactoryView::cria(string opcao){
    if (opcao=="MENU") return new menuView;
    else if (opcao=="INSERE") return new insereView;
    else return NULL;
}
