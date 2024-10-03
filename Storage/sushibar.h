/*
    Header for parent class
*/

#ifndef SUSHIBAR_H
#define SUSHIBAR_H

#include "../restaurant.h"
#include "../Data/sushi.h"
#include "../Data/menu.h"

class SushiBar {
    //Private Variables --------------------------------
    private:
        Sushi **sushi;
        float tab;
        float tax;
        float total;
        int numSushi;
    //public which stores the getters setters and constructors:
    public:
        //getters
        int getNumSushi();
        float getTab();
        float getTax(); 
        float getTotal(); 
        Sushi* getSushi(int index);
        
        //setters
        void setNumSushi(int numSushi);
        void loadSushi(Menu &menu);
        void setTab(float tab);
        void setTax(float tax);
        void updateTab(float cost);



        SushiBar (Menu &menu) { //overloaded constructor
            this->numSushi = menu.getNumSushi();
            loadSushi(menu);
            this->tab = 0.0;
            this->tax = 0.0;
            this->total = 0.0;
        }


        ~SushiBar (){ //destructor
            for (int i = 0; i < numSushi ; ++i)
            {
                delete [] this->sushi[i];
            } 
            delete [] this->sushi;
        }

 
};

#endif