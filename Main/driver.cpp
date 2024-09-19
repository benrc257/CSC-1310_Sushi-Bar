/*
    Main function
    Authors: Alec Szczechowicz, Benjamin Clark, Silas Garmon, Lucas Starkey
    Date: 9/12/2024
    Description: This program simulates a Sushi Bar with a conveyor belt that sends random dishes with sushi out to the customer.
*/

#include "../restaurant.h"
#include "../Storage/sushibar.h"

int main() {
    //variables
    Menu menu;
    SushiBar sushiBar(menu);
    Sushi* currentSushi = NULL;
    int highScore = 0, choicesLeft;
    char choice;
    time_t seed;
    
    cout << "\n\n##### WELCOME TO THE SUSHI BAR #####"
         << "\nYou will be shown a selection of sushi,"
         << "\nserved to you on a conveyor belt. You"
         << "\nmay select up to " << CHOICES << "sushi, each"
         << "\nwith a different rarity and price. You"
         << "\nwill only shown " << REROLLS << "sushi. Choose wisely!"
         << "\n####################################\n";

    cout << "\nPRESS ENTER TO BEGIN";
    cin >> choice;
    cin.clear();
    cin.ignore(10000,'\n');

    do {
        choicesLeft = CHOICES;
        for (int i = 0; i < REROLLS; i++) { // this loop controls the number of rerolls

            // spinning message + delay
            cout << "\nSPINNING";
            for (int j = 0; j < 3; j++) {
                delay(1);
                cout << ".";
            }
            cout << "\n";

            // generates random number between 0 and max # of sushi and passes it to getSushi()
            currentSushi = sushiBar.getSushi(randnum(0, sushiBar.getNumSushi()));

            // prints sushi to screen
            cout << (*currentSushi).getRarity() << "\n"
                << (*currentSushi).getName() << "\n"
                << "INGREDIENTS:\n";

            for (int j = 0; j < (*currentSushi).getIngredientsSize(); j++) { // prints each ingredient
                cout << j+1 << ". \t" << (*currentSushi).getIngredient(j) << "\n";
            }

            cout << "PRICE: " << (*currentSushi).getCost() << "\n\n";

            // asks the user if they would like to take the sushi
            cout << "You have " << choicesLeft << " choices remaining.\n"
                << "Take this sushi? (Y/N) >> ";
            
            while (cin >> choice || (toupper(choice) != 'N' || toupper(choice) != 'Y')) {
                cout << "\nInvalid choice. Please enter Y or N. >> ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (toupper(choice) == 'Y') {
                choicesLeft--;
                cout << "\nYou took \"" << (*currentSushi).getName() << "\" off the conveyor!\n";
            } else {
                cout << "\nYou took \"" << (*currentSushi).getName() << "\" off the conveyor!\n";
            }

            if (choicesLeft < 1) {
                cout << "\nYou have 0 choices left. Here is your total!\n";
                break;
            }
        }

        // displaying score
        if (sushiBar.getTotal() > highScore) {
            cout << "\n***NEW HIGHSCORE***\n";
            highScore = sushiBar.getTotal();
        }

        cout << fixed << setprecision(2) << showpoint;
        cout << "PRICE: $" << sushiBar.getTab() << "\n"
            << "TAX:   $" << sushiBar.getTax() << "\n"
            << "TOTAL: $" << sushiBar.getTotal() << "\n";
        
        // asking the user if they would like to play again
        cout << "\nPlay again? (Y/N) >> ";
        while (cin >> choice || (toupper(choice) != 'N' || toupper(choice) != 'Y')) {
            cout << "\nInvalid choice. Please enter Y or N. >> ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (choice == 'N'); // game ends if the user selects N

    return 0;
}