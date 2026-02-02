#include "Ninja.h"

Ninja::Ninja(std::string n, std::string v, double l, std::string c, double s, double d, std::string r): name(n), village(v), chakra_level(l), clan(c), strength(s), speed(d), rank(r) {}

void Ninja::display() {
    std::cout << "name: " << name << " | village: " << village << " | chakra level: " << chakra_level << " | clan: " << clan << " | strength: " << strength << " | speed: " << speed << " | rank: " << rank << std::endl;
}
