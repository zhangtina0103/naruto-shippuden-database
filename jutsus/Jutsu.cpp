#include "Jutsu.h"

Jutsu::Jutsu(std::string n, double c, double d) : name(n), chakra_cost(c), difficulty(d) {}

void Jutsu::display(){
    std::cout << "name: " << name << " | difficulty: " << difficulty << " | chakra cost: " << chakra_cost << std::endl;
}
