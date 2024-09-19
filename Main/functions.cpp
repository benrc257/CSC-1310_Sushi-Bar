/*
    File for helper functions
*/

#include "../restaurant.h"

void delay(int delay) {
    //variables
    time_t timer;

    //obtain start time and the end time
    timer = time(0)+delay;

    while (time(0) < timer);
}

int randnum(int low, int high) {
    
    return rand()%(high-low+1)+low;

}

/*
//Function to display the menu items to show the user what is on the conveyer belt.
void displayMenu () {

}

//Function is called when user selects a menu item.
void addToTab() {

}

//Void function when the user is done eating sushi this will calculate the bill based off how much Sushi was eaten.
void payTab () {

}


*/
