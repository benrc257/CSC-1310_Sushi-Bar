/*
    Header for parent class
*/

#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "restaurant.h"

class SushiBar {

    private:
        Sushi *sushi;
        double tab;
        double tax;
        double total;

    public:
        void loadSushi(ifstream&);
        Sushi getSushi(int);
        void updateTab();

        SushiBar () {
            this->sushi = NULL;
            this->tab = 0.0;
            this->tax = 0.0;
            this->total = 0.0;
        }
};

#endif