#include <bits/stdc++.h>

using namespace std;

class Model{
    private:
        string user;
        string pass;
    public:
        Model(){
            user = "admin";
            pass = "admin";
        }

        bool autentica(string u, string p){
            if (user == u && pass == p) return true;
            return false;
        }


};

class View{
    public:
        int showMenu(){
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

        int showMenuAdmin(){
            //TODO: Verificar as opções para admin (Registrar Eventos, remover eventos e etc);
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




};

class Presenter{
    private:
        bool isLogged;
        int op;
        View *v;
        Model *m;
    public:
        Presenter(){
            v = new View;
            m = new Model();
            isLogged = false;
        }

        void autenticar(string user, string pass){
            isLogged = m->autentica(user,pass);
        }

        bool menu(){
            if(!isLogged) op = v->showMenu();
            else op = v->showMenuAdmin();

            switch(op){
                case 0:
                    cout << "Obrigado por utilizar o programa" << endl;
                    return false;
                break;
            }

            return true;
        }

};

int main(int argc, char *argv[]){
    Presenter *p = new Presenter();

    if (argc!=1 && argc!=3){
        cout << "Sintaxe: ./Programa ou ./Programa login senha" << endl;
        return (0);
    }

    if (argc==3){
            p->autenticar(argv[1],argv[2]);
    }

    while(p->menu());

    return (0);
}
