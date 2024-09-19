/*
    Header for daughter menu class
*/

#ifndef MENU_H
#define MENU_H

#include "../restaurant.h"

const string FILENAME = "menu.csv";

class Menu {
    private:
        ifstream file;
        int numSushi;
        int* cost;
        int* ingredientsSize;
        string* sushiname;
        string* rarity;
        string** ingredients;

    public:
        void openFile();
        void openFile(string fileName);
        void readFile();

        //getters
        int* getCostArray();
        int* getSizeArray();
        string* getNameArray();
        string* getRarityArray();
        string** getIngredientsArray();

        //setters
        

        //constructor
        Menu() { //default constructor
            openFile(FILENAME);
            readFile();
        }

        Menu(string input) { //with filename input
            openFile(input);
            readFile();
        };

        //destructors
        ~Menu() {
            for (int i = 0; i < (*this->sushiname).size(); i++) {
                delete [] this->ingredients[i];
            }
            delete [] this->cost;
            delete [] this->ingredientsSize;
            delete [] this->sushiname;
            delete [] this->rarity;
            delete [] this->ingredients;
            this->file.close();
        }
};


#endif