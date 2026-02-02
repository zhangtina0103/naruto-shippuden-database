#ifndef NINJUTSU_H
#define NINJUTSU_H

#include <string>
#include <iostream>
#include "Jutsu.h"

// inherit from Jutsu
// Ninjutsu eg Rasengan etc need element
class Ninjutsu : public Jutsu {
public:
    std::string element;

    Ninjutsu(std::string n, double c, double d, std::string e);
    void display() override;

};


#endif
