#pragma once

#include <string>
#include "Cake.h"
#include <list>

class CakeDepot {
private:
    list<Cake*> cakesD;
    int max_capacity;
    int current_capacity;

public:
    CakeDepot(int max_capacity)
    {
        this->max_capacity = max_capacity;
        this->current_capacity = 0;
    }

    void AddCake(Cake* cake)
    {
        if (current_capacity < max_capacity) {
            cakesD.push_back(cake);
            current_capacity++;
        }
        else {
            cout << "Depozitul este plin." << endl;
        }
    }
    bool check_if_in_deposit(string cake_name)
    {
        for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
            Cake* iterator = *it;
            if (iterator->get_name() == cake_name)
            {
                return true;
            }
        }
        return false;
    }

    void RemoveCake(string name)
    {
        for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
            if ((*it)->get_name() == name) {
                cakesD.erase(it);
                current_capacity--;
                // cout << "Prajitura a fost stearsa din depozit." << endl;
                return;
            }
        }
        //cout << "Prajitura nu a fost gasita in depozit." << endl;
    }

    void DisplayCakes()
    {
        for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
            cout << (*it)->get_name() << " - " << (*it)->get_recipe().get_time() << " minute." << endl;
        }
        cout << endl;
    }

    int get_max_capacity()
    {
        return max_capacity;
    }

    int get_current_capacity()
    {
        return current_capacity;
    }

    list<Cake*> get_cakes()
    {
        return this->cakesD;
    }

    int get_time_D(Cake* it)
    {
        return it->get_recipe().get_time();
    }

};


