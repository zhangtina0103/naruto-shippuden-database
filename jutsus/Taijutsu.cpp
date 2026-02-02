#include "Taijutsu.h"

Taijutsu::Taijutsu(std::string n, double c, double d, std::string s, std::string b) : Jutsu(n, c, d), combat_style(s), body_requirement(b){}

void Taijutsu::display() {
    std::cout << "name: " << name << " | difficulty: " << difficulty << " | chakra cost: " << chakra_cost << " | combat style: " << combat_style << " | body requirement: " << body_requirement << std::endl;
}
