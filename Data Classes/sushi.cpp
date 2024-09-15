/*
    File for daughter/data class
*/

#include "sushi.h"

//Function to create a new sushi dish
Sushi* createSushi (float cost, int ingredientsSize, string* ingredients, string rarity) {
    Sushi* sushi = NULL;
    sushi = new Sushi(cost, ingredientsSize, ingredients, rarity);
    return sushi;
}

//Sushi function that will take user input on menu selection
Sushi selectSushi () {

}



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
void Sushi::setRarity(string) {
    this->rarity = rarity;
}

//Gets the price of the sushi
float Sushi::getCost() {
    return this->cost;
}

//Gets the size of the ingredients array
int Sushi::getIngredientsSize() {
    return (*this->ingredients).size();
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

