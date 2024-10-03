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
    string choice;
    time_t seed;

    //seed random number generator
    srand(time(0));
    
    //intro screen
    cout << "\n\n##### WELCOME TO THE SUSHI BAR #####"
         << "\nYou will be shown a selection of sushi,"
         << "\nserved to you on a conveyor belt. You"
         << "\nmay select up to " << CHOICES << " sushi, each"
         << "\nwith a different rarity and price. You"
         << "\nwill only shown " << REROLLS << " sushi. Choose wisely!"
         << "\n####################################\n";

    cout << "\nPRESS ENTER TO BEGIN";
    cin.ignore(10000, '\n');
    cin.clear();

    //game loop
    do {
        choice = "";
        choicesLeft = CHOICES;
        for (int i = 0; i < REROLLS && CHOICES > 0;) { // this loop controls the number of rerolls

            // spinning message + delay
            cout << "\nSPINNING...";
            delay(1);
            cout << "\n\n";

            // generates random number between 0 and max index of sushi and passes it to getSushi()
            currentSushi = sushiBar.getSushi(randnum(sushiBar.getNumSushi()-1));
            
            // prints sushi to screen
            cout << currentSushi->getRarity() << "\n"
                << currentSushi->getName() << "\n"
                << "INGREDIENTS: "
                << currentSushi->getIngredient(0);

            for (int j = 1; j < currentSushi->getIngredientsSize(); j++) { // prints each ingredient
                cout << "," << currentSushi->getIngredient(j);
            }
            cout << "\n";

            // prints price of sushi
            cout << fixed << setprecision(2) << showpoint;
            cout << "PRICE: $" << currentSushi->getCost() << "\n\n";

            // asks the user if they would like to take the sushi
            cout << "You have " << choicesLeft << " choices and " << REROLLS-(i+1) << " rerolls remaining\n"
                << "Take " << currentSushi->getName() << " or reroll? (T/R) >> ";
            
            while (!(cin >> choice) || !(toupper(choice.front()) == 'T' || toupper(choice.front()) == 'R')) {
                cout << "\nInvalid choice. Please enter Y or N. >> ";
                cin.clear();
                cin.ignore(10000, '\n');
            }

            if (toupper(choice.front()) == 'T') {
                choicesLeft--;
                cout << "\nYou took \"" << currentSushi->getName() << "\" off the conveyor!\n";
                sushiBar.updateTab(currentSushi->getCost());
            } else {
                i++;
                cout << "\nYou skipped \"" << currentSushi->getName() << "\".\n";
            }

            //checks how many choices are left
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

        // prints price, tax, and total
        cout << fixed << setprecision(2) << showpoint;
        cout << "PRICE: $" << sushiBar.getTab() << "\n"
            << "TAX:   $" << sushiBar.getTax() << "\n"
            << "TOTAL: $" << sushiBar.getTotal() << "\n";
        
        // asking the user if they would like to play again
        cout << "\nPlay again? (Y/N) >> ";
        while (!(cin >> choice) || !(toupper(choice.front()) == 'N' || toupper(choice.front()) == 'Y')) {
            cout << "\nInvalid choice. Please enter Y or N. >> ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

    } while (toupper(choice.front()) == 'Y'); // game ends if the user selects N

    return 0;
}