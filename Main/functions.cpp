/*
    File for helper functions
*/

#include "../restaurant.h"
#include "../Storage/sushibar.h"

//creates a delay
void delay(int delay) {
    //variables
    time_t timer;

    //obtain start time and the end time
    timer = time(0)+delay;

    while (time(0) < timer);
}

//generates a random number between 0 and max
int randnum(int max) {
    int random = rand()%(max+1);
    return random;
}







