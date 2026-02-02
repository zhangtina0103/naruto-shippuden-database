#ifndef TAIJUTSU_H
#define TAIJUTSU_H

#include <string>
#include <iostream>
#include "Jutsu.h"

// inherit from Jutsu
// Taijutsu eg Leaf Hurricane etc are pure physical
class Taijutsu : public Jutsu {
public:
    std::string combat_style;
    std::string body_requirement;

    Taijutsu(std::string n, double c, double d, std::string s, std::string b);
    void display() override;
};


#endif
