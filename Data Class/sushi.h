/*
    Header for daughter/data class
*/

#ifndef SUSHI_H
#define SUSHI_H

#include "restaurant.h"

//Class that defines Sushi and its ingredients
class Sushi {
    public:
    Sushi() {

    }

    private:
    int sushiCount;
    int cost;
    string* ingredients;
    string rarity;

};


Sushi createSushi(int, int, string*, string);
Sushi selectSushi();



#endif