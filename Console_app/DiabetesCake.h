#pragma once

#include "Cake.h"
#include "Recipe.h"
#include <string>
#include <iostream>
using namespace std;

class DiabetesCake : public Cake {
private:
    int sugar_amount;
public:
    DiabetesCake(string name, Recipe recipe, bool tip, int sugar_amount) : Cake(name, recipe, tip)
    {
        this->sugar_amount = sugar_amount;
    }
    int get_sugar_amount()
    {
        return this->sugar_amount;
    }
    void Display() {
        this->display_c();
        cout << "Cantitate de zahar: " << this->sugar_amount << " grame." << endl;
    }
};

