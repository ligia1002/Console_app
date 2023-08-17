#include "Recipe.h"

Recipe::Recipe() {}
Recipe::Recipe(std::string name, int time) : name(name), time(time) {}

std::string Recipe::get_name() {
    return name;
}

int Recipe::get_time() {
    return time;
}
