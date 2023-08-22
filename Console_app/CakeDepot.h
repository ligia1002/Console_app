#pragma once

#include <string>
#include "Cake.h"
#include <list>

class CakeDepot {
private:
    std::list<Cake*> cakesD;
    int max_capacity;
    int current_capacity;

public:
    CakeDepot(int max_capacity);
    void AddCake(Cake* cake);
    bool check_if_in_deposit(std::string cake_name);
    void RemoveCake(std::string name);
    void DisplayCakes();
    int get_max_capacity();
    int get_current_capacity();
    std::list<Cake*> get_cakes();
    int get_time_D(Cake* it);
};



