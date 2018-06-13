#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <bits/stdc++.h>

using namespace std;

class Presenter;

class View{
    private:
        Presenter *p;
    public:

        int showMenu();

        int showMenuAdmin();

        void setPresenter(Presenter *pres);

        /*TODO: View para cadastro de evento e remoção de evento
        View para busca de evento e listarEvento
        */

        void bye();
};

#endif
