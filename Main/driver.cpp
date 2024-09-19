/*
    Main function
    Authors: Alec Szczechowicz, Benjamin Clark, Silas ---, Lucas Starkey
    Date: 9/12/2024
    Description: This program simulates a sushibar with a conveyor belt that sends random dishes with sushi out to the customer.
*/

#include "../restaurant.h"

int main() {
    //variables
    SushiBar sushiBar = {};
    Menu menu = {};
    Sushi* currentSushi = NULL;
    int highScore = 0;
    char choice;
    time_t seed;
    
    cout << "\n\n##### WELCOME TO THE SUSHI BAR #####";
         << "\nYou will be shown a selection of sushi,"
         << "\nserved to you on a conveyor belt. You"
         << "\nmay select up to " << CHOICES << "sushi, each"
         << "\nwith a different rarity and price. You"
         << "\nwill only shown " << REROLLS << "sushi. Choose wisely!"
         << "\n####################################\n";

    cout << "\nPRESS ENTER TO BEGIN";
    cin >> choice;
    cin.clear();
    cin.ignore(10000,"\n");

    for (int i = 0; i < REROLLS; i++) { // this loop controls the number of rerolls

        //spinning message + delay
        cout << "\nSPINNING";
        for (int j = 0; j < 3; j++) {
            delay(1);
            cout << ".";
        }
        cout << "\n";

        // generate random number and pass it to select sushi
        currentSushi = SushiBar.selectSushi(randnum());


    }


    

    
    return 0;
}