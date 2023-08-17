#pragma once
#include <string>

class Recipe {

private:
    std::string name;
    int time;

public:
    Recipe();
    Recipe(std::string name, int time);

    std::string get_name();
    int get_time();

 
};

