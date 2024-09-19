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
        //construct a sushi using info from menu
        sushi[i] = Sushi(menu.getCostArray()[i],menu.getSizeArray()[i],menu.getIngredientsArray()[i],menu.getRarityArray()[i]);
    }
};

void SushiBar::setTab(float tab){
    this->tab = tab;
};

void SushiBar::setTax(float tax){
    this->tax = tax;
};

void SushiBar::updateTab(int indexOfSushi){
    this->tab -= this->sushi[indexOfSushi].getCost();
};

float SushiBar::getTab(){
    return this->tab;
};

Sushi SushiBar::getSushi(int index){
    return this->sushi[index];
};