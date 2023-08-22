#pragma once

#include "Cake.h"
#include "Recipe.h"
#include <string>

class DiabetesCake : public Cake {
private:
    int sugar_amount;
public:
    DiabetesCake(std::string name, Recipe recipe, bool tip, int sugar_amount);
    int get_sugar_amount();
    void Display();
};

