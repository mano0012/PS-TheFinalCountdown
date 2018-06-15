#include "View.hpp"

void View::setPresenter(Presenter *presenter){
    p = presenter;
}

void View::start(View *view){
    if (view != NULL){
        cout << "Not NULL" << endl;
    } else {
        cout << "NULL" << endl;
        p->teste();
    }

}
