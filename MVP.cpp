#include <bits/stdc++.h>
#include "View.cpp"
#include "Presenter.cpp"
using namespace std;

main(){
    ContractView *v;

    v = FactoryView::cria("MENU");
    v->start(NULL);
}
