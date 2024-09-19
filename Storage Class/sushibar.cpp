/*
    File for parent class
*/

#include "sushibar.h"

using namespace std;

 void SushiBar::loadSushi(Menu &menu){

    int numSushi = menu.getNumSushi();
    this->sushi = new Sushi[numSushi];
    for (int i = 0; i < numSushi; i++)
    {
        sushi[i] = Sushi(menu.getCostArray()[i],menu.getSizeArray()[i],menu.getIngredientsArray()[i],menu.getRarityArray()[i]);
    }
    


};
