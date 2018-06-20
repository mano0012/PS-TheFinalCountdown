#ifndef CONTRACT_HPP_
#define CONTRACT_HPP_

#include <bits/stdc++.h>

using namespace std;

class ContractMenu{
    public:
        class View{
            public:
                virtual void change(string option) = 0;
                virtual void setPresenter() = 0;
                virtual int showMenu() = 0;
                virtual void start() = 0;
        };

        class Presenter{
            public:
                ContractMenu::View *view;
                virtual void setView(ContractMenu::View *v) = 0;
                virtual void start() = 0;
        };
};

class ContractInsere{
    public:
        class View{
            public:
                virtual void start(ContractMenu::View *last) = 0;
                virtual int criaEvento() = 0; //Utilizar Builder
        };

        class Presenter{
            public:
                ContractInsere::View *view;

                virtual void setView(ContractInsere::View *v) = 0;
                virtual void start() = 0;

        };
};
#endif
