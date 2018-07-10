#include "Contract.hpp"
#include "Presenter.cpp"

//Fabrica que irá criar as Views
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
                cout << "Opção invalida, digite novamente: ";
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

        void endOfLife(){
            cout << "ADEUS\n" << endl;
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

            cout << "Digite o dia de finalização do Evento: ";
            cin >> data;
            evento->dataFim->setDia(data);
            cout << "Digite o mes de finalização do Evento: ";
            cin >> data;
            evento->dataFim->setMes(data);
            cout << "Digite o ano de finalização do Evento: ";
            cin >> data;
            evento->dataFim->setAno(data);

            cout << "Digite a descrição do evento: ";
            cin >> evento->desc;

            evento->isVisible = false;

        }

        void changeView(classView option){
            ContractView *newView;
            delete presenter;

            newView = FactoryView::cria(option);
            newView->start(this);

        }
};

class listaView : public ContractListaView {

    void setPresenter(){
            presenter = new inserePresenter;
            presenter->setView(this);
            presenter->start();
    }

    int showMenu(){
        int op;
        cout << "1 - Buscar por nome\n2- Buscar por data\nSelecione a opcao: ";

        cin >> op;
        while (op!=1 || op!=2){
            cout << "Opcao invalida, digite novamente: ";
            cin >> op;
        }

        return op;

    }

    int mostraListaEventos(lista *eventos){
        int i = 1;
        if (eventos!=NULL){
            cout << endl << "Nao ha eventos" << endl;
            return 0;
        }

        while (eventos != NULL){
            cout << "--------------------------------------" << endl;
            cout << "ID: " << i << endl;
            cout << "Nome: " << eventos->evento->nome << endl;
            //cout << "Local: " << eventos->evento->local << endl;
            cout << "Data inicio: " << eventos->evento->dataInicio->getData() << endl;
            cout << "Data fim: " << eventos->evento->dataFim->getData() << endl;
            //cout << "Descricao: " << eventos->evento->desc << endl;
            cout << "--------------------------------------" << endl;

            i++;
            eventos = eventos->prox;
        }

        cout << "Selecione um evento: " << endl;
        cin >> i;

        return i;

    }

    void mostraEventoEspecifico(Evento *evento){
        cout << "--------------------------------------" << endl;
        cout << "Nome: " << evento->nome << endl;
        cout << "Local: " << evento->local << endl;
        cout << "Data inicio: " << evento->dataInicio->getData() << endl;
        cout << "Data fim: " << evento->dataFim->getData() << endl;
        cout << "Descricao: " << evento->desc << endl;
        cout << "--------------------------------------" << endl;
    }

    string buscaNome(){
        string nome;
        cout << "Digite o nome do evento: ";
        cin >> nome;
        return nome;
    }

    Data buscaData(){
        int data;
        Data dataEvento;

        cout << "Digite o dia de inicio do Evento: ";
        cin >> data;
        dataEvento.setDia(data);
        cout << "Digite o mes de inicio do Evento: ";
        cin >> data;
        dataEvento.setMes(data);
        cout << "Digite o ano de inicio do Evento: ";
        cin >> data;
        dataEvento.setAno(data);

        return dataEvento;
    }

    void changeView(classView option){
        ContractView *newView;
        delete presenter;

        newView = FactoryView::cria(option);
        newView->start(this);

    }

}

//Função de criação
ContractView * FactoryView::cria(classView opcao){
    switch(opcao){
        case MENU:
            return new menuView;
        break;
        case INSERE:
            return new insereView;
        break;
        case LISTAR:
            return new listaView;
        break;
        default:
            return NULL;
        break;
    /*if (opcao=="MENU") return new menuView;
    else if (opcao=="INSERE") return new insereView;
    else return NULL;*/
    }
}
