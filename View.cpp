#include "View.hpp"

int View::showMenu(){
    int op;
    cout << "=======Menu=======" << endl;
    cout << "1- Listar eventos\n2- Procurar evento\n0- Sair" << endl;
    cout << "Selecione a opcao: ";
    cin >> op;
    while(op<0 || op>2){
        cout << "Opcao invalida, digite novamente: ";
        cin >> op;
    }
    return op;
}

int View::showMenuAdmin(){
    int op;
    cout << "=======Menu=======" << endl;
    cout << "1- Listar eventos\n2- Procurar evento\n3- Cadastrar evento\n4- Remover evento\n5- Alterar evento\n0- Sair" << endl;
    cout << "Selecione a opcao: ";
    cin >> op;
    while(op<0 || op>2){
        cout << "Opcao invalida, digite novamente: ";
        cin >> op;
    }
    return op;
}

void View::setPresenter(Presenter *pres){
    p = pres;
}

/*TODO: View para cadastro de evento e remoção de evento
View para busca de evento e listarEvento
*/

void View::bye(){
    cout << "Obrigado por utilizar o programa" << endl;
}
