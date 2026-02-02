#include "Ninjutsu.h"

Ninjutsu::Ninjutsu(std::string n, double c, double d, std::string e) : Jutsu(n, c, d), element(e) {}

void Ninjutsu::display() {
    std::cout << "name: " << name << " | difficulty: " << difficulty << " | chakra cost: " << chakra_cost << " | element: " << element << std::endl;
}
