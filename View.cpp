#include "Contract.hpp"
#include "Presenter.cpp"

class insereView : public ContractInsere::View{
    public:
        ContractInsere::Presenter *presenter;

        void start(ContractMenu::View *last){
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
};

class menuView : public ContractMenu::View {
    public:
        ContractMenu::Presenter *presenter;

        void start(){
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
                cout << "Opção invalida, digite novamente: ";
                cin >> op;
            }

            return op;
        }

        void change(string option){
            ContractInsere::View *newView;
            delete presenter;

            newView = new insereView;
            newView->start(this);
        }

};


