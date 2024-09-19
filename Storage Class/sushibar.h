/*
    Header for parent class
*/

#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "../restaurant.h"

class SushiBar {

    private:
        Sushi **sushi;
        float tab;
        float tax;
        float total;
        int numSushi;

    public:
        //getters
        int getNumSushi();
        float getTab();
        float getTax(); // this need to be implemeted
        float getTotal(); // this need to be implemeted
        Sushi getSushi(int index);

        
        //setters
        void setNumSushi(int numSushi);
        void loadSushi(Menu &menu);
        void setTab(float tab);
        void setTax(float tax);
        void updateTab(int indexOfSushi); // the int needs to be the index of the sushi, not the price



        SushiBar (Menu &menu) {
            loadSushi(menu);
            this->tab = 0.0;
            this->tax = 0.0;
            this->total = 0.0;
        }


        ~SushiBar (){
            for (int i = 0; i < numSushi ; ++i)
            {
                delete [] this-> sushi[i];
            } 
            delete [] this->sushi;
        }

 
};

#endif