#pragma once
#include "Cake.h"
#include "Recipe.h"
#include <string>

class NormalCake : public Cake {
public:
    NormalCake(string name, Recipe recipe, bool tip) : Cake(name, recipe, tip) { }
    void Display() {
        this->display_c();
    }
    int get_sugar_amount() { return 0; }
};

