#include "Model.hpp"

void Data::setDia(int d){
    dia = d;
}

void Data::setMes(int m){
    mes = m;
}

void Data::setAno(int a){
    ano = a;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}

string Data::getData(){
    string d,m,a;

    d = to_string(dia);
    m = to_string(mes);
    a = to_string(ano);

    d.insert(d.begin(), 2 - d.length(), '0');
    m.insert(m.begin(), 2 - m.length(), '0');

    return d + "/" + m + "/" + a;
}

void Data::setCampos(string data){
    istringstream dia(data.substr(0,2));
    istringstream mes(data.substr(3,2));
    istringstream ano(data.substr(6,4));
    int dados;

    dia >> dados;

    setDia(dados);

    mes >> dados;

    setMes(dados);

    ano >> dados;

    setAno(dados);
}

Evento * criaEvento(){
    Evento *evento = new Evento;

    return evento;
}

void inserirEvento(Evento *evento){
    lista *aux = (lista *)malloc(sizeof(lista));
    lista *temp;
    bool inseriu = false;


    aux->ant = NULL;
    aux->prox = NULL;
    aux->evento = evento;

    if (listaEventos!=NULL){
        temp = listaEventos;

        if (temp->evento->dataInicio->getDia() > aux->evento->dataInicio->getDia()){
            aux->prox = temp;
            temp->ant = aux;
            listaEventos = aux;
        } else {
            while (!inseriu){
                if (temp->prox != NULL){
                    temp = temp->prox;

                    if (temp->evento->dataInicio->getDia() > aux->evento->dataInicio->getDia()){
                        aux->prox = temp;
                        aux->ant = temp->ant;
                        temp->ant->prox = aux;
                        temp->ant = aux;
                        inseriu = true;
                    }
                } else {
                    temp->prox = aux;
                    aux->ant = temp;
                    inseriu = true;
                }
            }

        }
    } else {
        listaEventos = aux;
    }
}

void gravaLista(int qtdEventos){
    ofstream arq;
    lista *temp = listaEventos;

    if (temp!=NULL){
        arq.open("Eventos.txt");
        arq << qtdEventos << endl;
        while (temp!=NULL){
            arq << temp->evento->getNome() << endl << temp->evento->getLocal() << endl << temp->evento->dataInicio->getData() << endl <<
            temp->evento->dataFim->getData() << endl << temp->evento->getDesc() << endl;
            temp = temp->prox;
        }

        arq.close();
    }

}

int recuperaLista(){
    ifstream arq;
    Evento *evento;
    string dados;
    string tamanho;
    int tamanhoLista = 0;

    arq.open("Eventos.txt");

    if (arq.is_open()){
        int i=0;

        getline(arq,tamanho);

        tamanhoLista = stoi(tamanho);

        while (i<tamanhoLista){
            evento = new Evento();

            getline(arq, dados);
            evento->setNome(dados);

            getline(arq, dados);
            evento->setLocal(dados);


            getline(arq, dados);
            evento->dataInicio->setCampos(dados);

            getline(arq, dados);
            evento->dataFim->setCampos(dados);


            getline(arq, dados);
            evento->setDesc(dados);

            inserirEvento(evento);
            evento = NULL;
            i++;
        }

        arq.close();
    }

    return tamanhoLista;

}

void libera(){
    lista *temp;

    temp = listaEventos;

    while (listaEventos!=NULL){
        listaEventos = listaEventos->prox;
        free (temp);
        temp = listaEventos;
    }
}

void getByName(string nome){
    lista *temp;

    temp = listaEventos;

    cout << "NOME: " << nome << endl;
    while(temp != NULL){
        cout << "EventName: " << temp->evento->getNome() << endl;
        if (nome == temp->evento->getNome()){
            cout << "MATCH" << endl;
            temp->evento->changeVisibility();
        }
        temp = temp->prox;
    }
}

void getByDate(Data data){
    lista *temp;

    temp = listaEventos;

    while(temp != NULL){
        if (data.getData() == temp->evento->dataInicio->getData()){
            temp->evento->changeVisibility();
            cout << "SETOU" << endl;
        }
        temp = temp->prox;
    }
}

/*TODO: Função para remover.

Caso seja inserido um evento com uma data no passado, exibir erro
*/

