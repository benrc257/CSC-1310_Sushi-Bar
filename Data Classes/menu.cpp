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

void Menu::readFile() { //THIS HASNT BEEN TESTED IDK IF IT WORKS
    string text, line, counter;
    size_t start = 4, end, readstart, readend, arrayLength = 0; //size_t used becaused of substr and find

    getline(this->file, text);

    line = text;
    while (line.find("new") != string::npos) {
        end = line.find("new");
        line = line.substr(end+4);
        arrayLength++;
    }
    
    this->numSushi = arrayLength;
    this->cost = new int[arrayLength];
    this->ingredientsSize = new int[arrayLength];
    this->sushiname = new string[arrayLength];
    this->rarity = new string[arrayLength];
    this->ingredients = new string*[arrayLength];


    for (int i = 0; i < arrayLength; i++) {
        end = text.find("new", start);
        line = text.substr(start, end);
        readstart = 0;
        readend = line.find(",");

        this->sushiname[i] = line.substr(readstart, readend);
        readstart = readend+1;
        readend = line.find(",", readstart);

        this->rarity[i] = line.substr(readstart, readend);
        readstart = readend+1;
        readend = line.find(",", readstart);

        this->ingredientsSize[i] = stoi(line.substr(readstart, readend));
        readstart = readend+1;
        readend = line.find(",", readstart);

        this->ingredients[i] = new string[this->ingredientsSize[i]];
        for (int j = 0; j < this->ingredientsSize[i] && readend != string::npos; j++) {
            this->ingredients[i][j] = line.substr(readstart, readend);
            readstart = readend+1;
            readend = line.find(",", readstart);
        }

        start = end+4;
    }
    file.close();
}


int* Menu::getCostArray() {
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