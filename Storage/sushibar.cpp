/*
    File for parent class
*/

#include "sushibar.h"

using namespace std;

void SushiBar::loadSushi(Menu &menu){
    int numSushi = menu.getNumSushi();
    setNumSushi(numSushi);
    float* costArray = menu.getCostArray();
    int* sizeArray =  menu.getSizeArray();
    string** ingredientsArray = menu.getIngredientsArray();
    string* rarityArray = menu.getRarityArray();
    string* nameArray = menu.getNameArray();




    this->sushi = new Sushi*[numSushi]; 
    for (int i = 0; i < numSushi; i++)
    {
        //construct a sushi using info from menu
        sushi[i] = new Sushi(costArray[i], sizeArray[i], ingredientsArray[i], rarityArray[i], nameArray[i]);
    }
};

//setters
void SushiBar::setNumSushi(int numSushi){
    this->numSushi = numSushi;
};


void SushiBar::setTab(float tab){
    this->tab = tab;
};

void SushiBar::setTax(float tax){
    this->tax = tax;
};

void SushiBar::updateTab(float cost){
    this->tab += cost;
    this->tax += (cost*TAX);
    this->total += (cost+(cost*TAX));
};

// getters

int SushiBar::getNumSushi(){
    return this->numSushi;
};

float SushiBar::getTab(){
    return this->tab;
};

float SushiBar::getTax() {
    return this->tax;
}

float SushiBar::getTotal() {
    return this->total;
}

Sushi* SushiBar::getSushi(int index){
    return this->sushi[index];
};

