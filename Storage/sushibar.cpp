/*
    File for parent class
*/

#include "sushibar.h"

using namespace std;

void SushiBar::loadSushi(Menu &menu){
    int numSushi = menu.getNumSushi();
    setNumSushi(numSushi);
    float* costArray = menu.getCostArray(); // get cost from costArray
    int* sizeArray =  menu.getSizeArray();  // Gets the size of the dish being offered.
    string** ingredientsArray = menu.getIngredientsArray(); // Gets the ingredients for every sushi dish.
    string* rarityArray = menu.getRarityArray();    //Gets the rarity for every dish generated.
    string* nameArray = menu.getNameArray();    //Gets the name for every dish.




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

//Starrts the initial tab for the first play through.
void SushiBar::setTab(float tab){
    this->tab = tab;
};

void SushiBar::setTax(float tax){
    this->tax = tax;
};

//Adds tht
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


