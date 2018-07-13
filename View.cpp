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

        int showAdminMenu(){
            int op;
            cout << "========MENU========" << endl;
            cout << "1- Inserir Evento\n2- Listar Eventos\n3- Remover evento\n0- Sair\nSelecione uma opcao: ";
            cin >> op;
            while (op<0 || op>3){
                cout << "Opção invalida, digite novamente: ";
                cin >> op;
            }

            return op;
        }

        int showMenu(){
            int op;
            cout << "========MENU========" << endl;
            cout << "1- Listar Eventos\n0- Sair\nSelecione uma opcao: ";
            cin >> op;
            while (op!=0 && op!=1){
                cout << "Opção invalida, digite novamente: ";
                cin >> op;
            }

            return op;
        }

        void changeView(classView option){
            ContractView *newView;
            deletePresenter();

            newView = FactoryView::cria(option);
            if (newView != NULL) newView->start(this);
        }

        void endOfLife(){
            cout << endl << "Gerenciamento de eventos utilizando arquitetura MVP\nDesenvolvido por: Luiz Gustavo e Marcos Souza" << endl;
        }

        void showExecutionError(string name){
            cout << "Sintaxe: " << name << " login senha ou " << name << endl;
        }

        void deletePresenter(){
            delete presenter;
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

            while (data < 1 || data > 31) {
                cout << "Dia invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataInicio->setDia(data);

            cout << "Digite o mes de inicio do Evento: ";
            cin >> data;

            while (data < 1 || data > 12) {
                cout << "Mes invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataInicio->setMes(data);

            cout << "Digite o ano de inicio do Evento: ";
            cin >> data;

            while (data < 2018) {
                cout << "Ano invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataInicio->setAno(data);

            cout << "Digite o dia de finalização do Evento: ";
            cin >> data;


            while (data < 1 || data > 31) {
                cout << "Dia invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataFim->setDia(data);

            cout << "Digite o mes de finalização do Evento: ";
            cin >> data;

            while (data < 1 || data > 12) {
                cout << "Mes invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataFim->setMes(data);

            cout << "Digite o ano de finalização do Evento: ";
            cin >> data;

            while (data < 2018) {
                cout << "Ano invalido, digite novamente: ";
                cin >> data;
            }

            evento->dataFim->setAno(data);

            while (evento->dataFim->getData() < evento->dataInicio->getData()){
                cout << "Nao e possivel inserir um evento que termina antes de comecar" << endl;
                cout << "INICIO: " << evento->dataInicio->getData() << endl;
                cout << "FIM: " << evento->dataFim->getData() << endl;

                cout << "Digite o dia de finalização do Evento: ";
                cin >> data;

                while (data < 1 || data > 31) {
                    cout << "Dia invalido, digite novamente: ";
                    cin >> data;
                }

                evento->dataFim->setDia(data);

                cout << "Digite o mes de finalização do Evento: ";
                cin >> data;

                while (data < 1 || data > 12) {
                    cout << "Mes invalido, digite novamente: ";
                    cin >> data;
                }

                evento->dataFim->setMes(data);

                cout << "Digite o ano de finalização do Evento: ";
                cin >> data;

                while (data < 2018) {
                    cout << "Ano invalido, digite novamente: ";
                    cin >> data;
                }

                evento->dataFim->setAno(data);
            }

            cout << "Digite a descrição do evento: ";
            setbuf(stdin, NULL);
            getline(cin , dados);
            evento->setDesc(dados);

            evento->visible = false;

        }

        void changeView(classView option){
            ContractView *newView;
            deletePresenter();

            newView = FactoryView::cria(option);
            if (newView != NULL) newView->start(this);

        }

        void deletePresenter(){
            delete presenter;
        }
};

class listaView : public ContractListaView {
    private:
        ContractListaPresenter *presenter;
        bool remover;
    public:
        listaView(){
            remover = false;
        }
        void setPresenter(){
                presenter = new listaPresenter;
                presenter->setView(this);
                presenter->start(remover);
        }

        void setRemover(){
            remover = true;
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
            cout << "Nao ha eventos para serem listados ou o ID nao existe" << endl;
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
            cout << "Selecione um evento (0 caso nao queira): ";
            cin >> id;
            return id;
        }

        void changeView(classView option){
            ContractView *newView;
            deletePresenter();

            newView = FactoryView::cria(option);
            if (newView != NULL) newView->start(this);

        }

        void deletePresenter(){
            delete presenter;
        }
};

class removerView : public ContractRemoverView {
    private:
        ContractRemoverPresenter *presenter;

    public:

        void setPresenter(){
            presenter = new removerPresenter;
            presenter->setView(this);
            presenter->start();
        }

        void removerEvento(){
            view = new listaView;
            view->setRemover();
            view->setPresenter();

            view->deletePresenter();
            delete view;
        }

        void errorMessage(){
            cout << "Nao foi possivel remover o evento" << endl;
        }

        void changeView(classView option){
            ContractView *newView;
            deletePresenter();

            newView = FactoryView::cria(option);
            if (newView != NULL) newView->start(this);

        }

        void deletePresenter(){
            delete presenter;
        }
};

//Função de criação de views
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
        case REMOVER:
            return new removerView;
        break;
        default:
            return NULL;
        break;
    }
}
