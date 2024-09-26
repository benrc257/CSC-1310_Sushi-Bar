/*
    File for libraries, function prototypes, global variables, structures
*/

#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <iostream>
#include <iomanip>
#include <cctype>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;

//global constants
const float TAX = 0.095;
const int REROLLS = 6; //the number of rerolls the user gets
const int CHOICES = 3; //the number of sushi the user can select 

//driver functions
void delay(int);
int randnum(int);

#endif