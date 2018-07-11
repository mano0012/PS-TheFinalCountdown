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
            string dados;

            cout << "Digite o nome do evento: ";
            setbuf(stdin, NULL);
            getline(cin , dados);
            evento->setNome(dados);

            cout << "Digite o local do evento: ";
            setbuf(stdin, NULL);
            getline(cin , dados);
            evento->setLocal(dados);

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
            setbuf(stdin, NULL);
            getline(cin , dados);
            evento->setDesc(dados);

            evento->visible = false;

        }

        void changeView(classView option){
            ContractView *newView;
            delete presenter;

            newView = FactoryView::cria(option);
            newView->start(this);

        }
};

class listaView : public ContractListaView {
    ContractListaPresenter *presenter;

    void setPresenter(){
            presenter = new listaPresenter;
            presenter->setView(this);
            presenter->start();
    }

    int showMenu(){
        int op;
        cout << "1 - Listar por nome\n2 - Listar por data\n3 - Listar todos\nSelecione a opcao: ";

        cin >> op;
        while (op<1 || op>3){
            cout << "Opcao invalida, digite novamente: ";
            cin >> op;
        }

        return op;

    }

    void noEvents(){
        cout << "Nao ha eventos para serem listados" << endl;
    }

    void mostraEvento(Evento *evento, int id){
        cout << "--------------------------------------" << endl;
        cout << "ID: " << id << endl;
        cout << "Nome: " << evento->getNome() << endl;
        cout << "Data inicio: " << evento->dataInicio->getData() << endl;
        cout << "Data fim: " << evento->dataFim->getData() << endl;
        cout << "--------------------------------------" << endl;
    }

    void mostrarDetalhes(Evento *evento){
        cout << "--------------------------------------" << endl;
        cout << "Nome: " << evento->getNome() << endl;
        cout << "Local: " << evento->getLocal() << endl;
        cout << "Data inicio: " << evento->dataInicio->getData() << endl;
        cout << "Data fim: " << evento->dataFim->getData() << endl;
        cout << "Descricao: " << evento->getDesc() << endl;
        cout << "--------------------------------------" << endl;
    }

    string buscaNome(){
        string nome;
        cout << "Digite o nome do evento: ";
        setbuf(stdin,NULL);
        getline(cin,nome);
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

    int selectEvents(){
        int id;
        cout << "Caso deseje exibir mais informacoes sobre um evento, digite o ID do evento (0 caso nao queira): ";
        cin >> id;
        return id;
    }

    void changeView(classView option){
        ContractView *newView;
        delete presenter;

        newView = FactoryView::cria(option);
        newView->start(this);

    }
};

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
