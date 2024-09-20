/*
    Header for daughter sushi class
*/

#ifndef SUSHI_H
#define SUSHI_H

#include "../restaurant.h"

//Class that defines Sushi and its ingredients
class Sushi {
    private:
        float cost;
        int ingredientsSize;
        string* ingredients;
        string name;
        string rarity;

    public:
        //member functions
        void setCost(float);
        void setIngredients(string*);
        void setRarity(string);

        float getCost();
        int getIngredientsSize();
        string* getIngredients();
        string getIngredient(int);
        string getRarity();
        string getName();

        //constructors
        Sushi(float cost, int ingredientsSize, string* ingredients, string rarity, string name) { //overloaded constructor with ingredients
            this->name = name;
            this->cost = cost;
            this->ingredientsSize = ingredientsSize;
            this->ingredients = new string[ingredientsSize];
            this->rarity = rarity;

            for (int i = 0; i < ingredientsSize && i < (*ingredients).size(); i++) {
                this->ingredients[i] = ingredients[i];
            }
        }

        Sushi(float cost, int ingredientsSize, string rarity, string name) { //overloaded constructor
            this->name = name;
            this->cost = cost;
            this->ingredients = new string[ingredientsSize];
            this->rarity = rarity;
        }

        Sushi() { //default constructor
            this->name = "";
            this->cost = 0.00;
            this->ingredients = new string[1];
            this->rarity = "";
        }

        //destructor
        ~Sushi() {
            delete [] ingredients;
        }
        
    };


Sushi* createSushi(float, int, string*, string); //cost, size of ingredients array, ingredients array, rarity
Sushi selectSushi();

#endif