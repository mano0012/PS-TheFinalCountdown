#ifndef PRESENTER_HPP_
#define PRESENTER_HPP_

#include "View.hpp"
#include "Model.cpp"
#include <bits/stdc++.h>

using namespace std;

class View;

class Presenter{
    private:
        View *v;
    public:
        void setView(View *v);

        void start();

        void teste();
};

#endif // PRESENTER_HPP_
