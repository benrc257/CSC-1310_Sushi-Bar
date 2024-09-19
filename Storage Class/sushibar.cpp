/*
    File for parent class
*/

#include "sushibar.h"

using namespace std;

 void SushiBar::loadSushi(Menu menu){

    this->sushi = new Sushi[menu.getNumSushi()];


};
