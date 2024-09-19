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


//Function to display the menu items to show the user what is on the conveyer belt.
void displayMenu(SushiBar &sushiBar) {
    // accesses a random sushi off the menu
    Sushi target = sushiBar.getSushi(randnum(0,sushiBar.getNumSushi()));


    
}

/*
//fuction to clear the console and reset it for the next menu item
void reset() {

}
//Function is called when user selects a menu item.
void addToTab() {

    // updates the tab 
    SushiBar.updateTab(index)
    return;
}






*/
