/*
    File for helper functions
*/

#include "../restaurant.h"
#include "../Storage/sushibar.h"

void delay(int delay) {
    //variables
    time_t timer;

    //obtain start time and the end time
    timer = time(0)+delay;

    while (time(0) < timer);
}

int randnum(int low, int high) {
    srand(time(0));
    return rand()%(high-low+1)+low;
}







