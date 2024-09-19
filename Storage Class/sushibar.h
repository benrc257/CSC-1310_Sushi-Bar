/*
    Header for parent class
*/

#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "../restaurant.h"

class SushiBar {

    private:
        Sushi *sushi;
        float tab;
        float tax;
        float total;

    public:
        void loadSushi(ifstream&);
        Sushi getSushi(int);
        double getTab;
        
        void setTab(float);
        void setTax(float);
        void updateTab(int); //the int needs to be the index of the sushi, not the price



        SushiBar () {
            this->sushi = NULL;
            this->tab = 0.0;
            this->tax = 0.0;
            this->total = 0.0;
        }
};

#endif