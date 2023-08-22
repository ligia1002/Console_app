#include "CakeDepot.h"
#include <iostream>

CakeDepot::CakeDepot(int max_capacity)
    : max_capacity(max_capacity), current_capacity(0) {}

void CakeDepot::AddCake(Cake* cake) {
    if (current_capacity < max_capacity) {
        cakesD.push_back(cake);
        current_capacity++;
    }
    else {
        std::cout << "Depozitul este plin." << std::endl;
    }
}

bool CakeDepot::check_if_in_deposit(std::string cake_name) {
    for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
        Cake* iterator = *it;
        if (iterator->get_name() == cake_name) {
            return true;
        }
    }
    return false;
}

void CakeDepot::RemoveCake(std::string name) {
    for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
        if ((*it)->get_name() == name) {
            cakesD.erase(it);
            current_capacity--;
            return;
        }
    }
}

void CakeDepot::DisplayCakes() {
    for (auto it = cakesD.begin(); it != cakesD.end(); it++) {
        std::cout << (*it)->get_name() << " - " << (*it)->get_recipe().get_time() << " minute." << std::endl;
    }
    std::cout << std::endl;
}

int CakeDepot::get_max_capacity() {
    return max_capacity;
}

int CakeDepot::get_current_capacity() {
    return current_capacity;
}

std::list<Cake*> CakeDepot::get_cakes() {
    return cakesD;
}

int CakeDepot::get_time_D(Cake* it) {
    return it->get_recipe().get_time();
}

