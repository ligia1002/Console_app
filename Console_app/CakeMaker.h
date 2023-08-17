#pragma once
#include <Windows.h>

#include "Recipe.h"
#include "Cake.h"
#include "DiabetesCake.h"
#include "NormalCake.h"

class CakeMaker {
public:
    Cake* prepare_cake(Recipe recipe, bool is_diabetes_cake, int sugar_amount = 0)
    {
        // Simulam prepararea prajiturii prin asteptarea timpului specificat in reteta
        //cout << "Va rugam asteptati " << recipe.get_time() << " minute pana se prepara prajitura. " << endl;
        Sleep(recipe.get_time() * 1000); // Sleep primeste timpul in milisecunde
        Cake* cake;
        if (is_diabetes_cake) {
            cake = new DiabetesCake(recipe.get_name(), recipe, is_diabetes_cake, sugar_amount);
        }
        else {
            cake = new NormalCake(recipe.get_name(), recipe, is_diabetes_cake);
        }

        return cake;
    }

};

