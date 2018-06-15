#ifndef VIEW_HPP_
#define VIEW_HPP_

#include <bits/stdc++.h>

using namespace std;

class Presenter;

class View {
    private:
        Presenter *p;
    public:
        void setPresenter(Presenter *p);

        void start(View *view);
};

/*class menuView {



}*/

#endif
