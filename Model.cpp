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
    a.insert(a.begin(), 4 - a.length(), '0');



    if (inverse){
        return a + "/" + m + "/" + d;
    } else return d + "/" + m + "/" + a;
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

void autenticaUsuario(string user, string pass){
    string login = "admin";
    string senha = "admin";

    if (user == login && pass == senha){
        autenticado = true;
    }
}

Evento * criaEvento(){
    Evento *evento = new Evento;

    return evento;
}

void changeInverse(){
    inverse = !inverse;
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
        changeInverse();

        if (temp->evento->dataInicio->getData() > aux->evento->dataInicio->getData()){
            aux->prox = temp;
            temp->ant = aux;
            listaEventos = aux;
        } else {
            while (!inseriu){
                if (temp->prox != NULL){
                    temp = temp->prox;

                    if (temp->evento->dataInicio->getData() > aux->evento->dataInicio->getData()){

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

        changeInverse();
    } else {
        listaEventos = aux;
    }
}

void incQtdEventos(){
    tamanhoLista++;
}

void decQtdEventos(){
    tamanhoLista--;
}

void gravaLista(){
    ofstream arq;
    lista *temp = listaEventos;


    arq.open("Eventos.txt");
    arq << tamanhoLista << endl;

    while (temp!=NULL){
        arq << temp->evento->getNome() << endl << temp->evento->getLocal() << endl << temp->evento->dataInicio->getData() << endl <<
        temp->evento->dataFim->getData() << endl << temp->evento->getDesc() << endl;
        temp = temp->prox;
    }

    arq.close();


}

int recuperaLista(){
    ifstream arq;
    Evento *evento;
    string dados;
    string tamanho;

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

void liberaLista(){
    lista *temp;

    temp = listaEventos;

    while (listaEventos!=NULL){
        listaEventos = listaEventos->prox;

        free(temp->evento->dataInicio);
        free(temp->evento->dataFim);
        free(temp->evento);
        free (temp);

        temp = listaEventos;
    }
}

void getByName(string nome){
    lista *temp;

    temp = listaEventos;

    while(temp != NULL){
        if (nome == temp->evento->getNome()){
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
        }
        temp = temp->prox;
    }
}

void removeEvent(){
    lista *temp = eventoRemover;
    lista *aux;

    if (temp->ant != NULL){
        aux = temp->ant;
        aux->prox = temp->prox;
        if(temp->prox!=NULL) temp->prox->ant = aux;
        free(temp);
    } else {
        listaEventos = temp->prox;
        if (listaEventos != NULL) listaEventos->ant = NULL;
        free(temp);
    }
}
