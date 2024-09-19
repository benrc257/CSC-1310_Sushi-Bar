/*
    Header for parent class
*/

#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "restaurant.h"

class SushiBar {

    private:
        Sushi *sushi;
        float tab;
        float tax;
        float total;
        float Tab;

    public:
        //getters
        float getTab();
        Sushi getSushi(int);
        
        //setters
        void loadSushi(Menu);
        void setTab(float);
        void setTax(float);
        void updateTab(int indexOfSushi); //the int needs to be the index of the sushi, not the price



        SushiBar () {
           // this->sushi = NULL;
            this->tab = 0.0;
            this->tax = 0.0;
            this->total = 0.0;
        }
};

#endif