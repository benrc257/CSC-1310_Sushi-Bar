/*
    File for daughter sushi class
*/

#include "sushi.h"

/*
    Function definitions for the class
*/

//Sets the price of the sushi
void Sushi::setCost(float cost) {
    this->cost = cost;
}

//Sets the ingredients array inside the class equal to the array that is passed
void Sushi::setIngredients(string* ingredients) {
    
    for (int i = 0; i < Sushi::getIngredientsSize() && i < (*ingredients).size(); i++) {
        this->ingredients[i] = ingredients[i];
    }

}

//Sets the rarity of the sushi
void Sushi::setRarity(string rarity) {
    this->rarity = rarity;
}

//Getters 
string Sushi::getName(){
    return this->name;
};

//Gets the price of the sushi
float Sushi::getCost() {
    return this->cost;
}

//Gets the size of the ingredients array
int Sushi::getIngredientsSize() {
    return this->ingredientsSize;
}

//Gets the contents of the ingredients array
string* Sushi::getIngredients() {
    return this->ingredients;
}

//Gets the value of the ingredients array at the given index, returning an empty string if accessing invalid indexes
string Sushi::getIngredient(int index) {
    return this->ingredients[index];
}

//Gets the rarity of the sushi
string Sushi::getRarity() {
    return this->rarity;
}

