#include "Genjutsu.h"

Genjutsu::Genjutsu(std::string n, double c, double d, std::string t, double dur) : Jutsu(n, c, d), target_sense(t), duration(dur) {}

void Genjutsu::display() {
    std::cout << "name: " << name << " | difficulty: " << difficulty << " with chakra cost: " << chakra_cost << " | target sense: " << target_sense << " | duration: " << duration << std::endl;
}
