#include "DiabetesCake.h"
#include <iostream>

DiabetesCake::DiabetesCake(std::string name, Recipe recipe, bool tip, int sugar_amount)
    : Cake(name, recipe, tip), sugar_amount(sugar_amount) {}

//sugar_amount(sugar_amount) {} // echivalent cu //  { this->sugar_amount = sugar_amount; }

int DiabetesCake::get_sugar_amount() {
    return sugar_amount;
}

void DiabetesCake::Display() {
    display_c();
    std::cout << "Cantitate de zahar: " << sugar_amount << " grame." << std::endl;
}

