#pragma once
#include <iostream>
#include <string>

#include "Recipe.h"

using namespace std;

class Cake {
private:
    string name;
    Recipe recipe;// utilizarea constructorului default, membrii clasei Recipe sunt initializati cu valori default
    bool tip;
public:

    Cake(string name, Recipe recipe, bool tip)
    {
        this->name = name;
        this->recipe = recipe;
        this->tip = tip;
    }

    void display_c() {
        cout << this->name << endl;
    }

    string get_name()
    {
        return this->name;
    }

    Recipe get_recipe()
    {
        return this->recipe;
    }
    bool get_tip()
    {
        return this->tip;
    }
    virtual void Display() = 0;
    virtual int get_sugar_amount() = 0;
};

