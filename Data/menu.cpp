/*
    File for daughter menu class
*/

#include "menu.h"


void Menu::openFile() {
    this->file.open(FILENAME);
};

void Menu::openFile(string fileName) {
    this->file.open(fileName);
};

void Menu::readFile() { 
    string text, line, counter;
    size_t end, readend, arrayLength = 0; //size_t used becaused of substr and find

    getline(this->file, text);

    line = text;
    while (line.find("new") != string::npos) {
        end = line.find("new");
        line = line.substr(end+4);
        arrayLength++;
    }
    
    this->numSushi = arrayLength;
    this->cost = new float[arrayLength];
    this->ingredientsSize = new int[arrayLength];
    this->sushiname = new string[arrayLength];
    this->rarity = new string[arrayLength];
    this->ingredients = new string*[arrayLength];

    text = text.substr(4);
    for (int i = 0; i < arrayLength; i++) {
        end = text.find(",new");
        if (end != string::npos) {
            line = text.substr(0, end);
        } else {
            line = text.substr(0);
        }
        
        readend = line.find(",");

        this->sushiname[i] = line.substr(0, readend);
        line = line.substr(readend+1);
        readend = line.find(",", 0);

        this->rarity[i] = line.substr(0, readend);
        line = line.substr(readend+1);
        readend = line.find(",", 0);

        if (this->rarity[i] == "poor") {
            this->rarity[i] = "POOR";
            this->cost[i] = 1.00;
        } else if (this->rarity[i] == "common") {
            this->rarity[i] = "COMMON";
            this->cost[i] = 3.00;
        } else if (this->rarity[i] == "uncommon") {
            this->rarity[i] = "UNCOMMON";
            this->cost[i] = 5.00;
        } else if (this->rarity[i] == "rare") {
            this->rarity[i] = "RARE";
            this->cost[i] = 10.00;
        } else if (this->rarity[i] == "legendary") {
            this->rarity[i] = "LEGENDARY";
            this->cost[i] = 100.00;
        }

        this->ingredientsSize[i] = stoi(line.substr(0, readend));
        line = line.substr(readend+1);
        readend = line.find(",", 0);

        this->ingredients[i] = new string[this->ingredientsSize[i]];
        for (int j = 0; j < this->ingredientsSize[i]; j++) {
            this->ingredients[i][j] = line.substr(0, readend);
            line = line.substr(readend+1);
            readend = line.find(",", 0);
        }

        text = text.substr(end+5);
    }
    
    file.close();
}


int Menu::getNumSushi(){
    return this->numSushi;
};

float* Menu::getCostArray() {
    return this->cost;
}


int* Menu::getSizeArray() {
    return this->ingredientsSize;
}


string* Menu::getNameArray() {
    return this->sushiname;
}


string* Menu::getRarityArray() {
    return this->rarity;
}


string** Menu::getIngredientsArray() {
    return this->ingredients;
}