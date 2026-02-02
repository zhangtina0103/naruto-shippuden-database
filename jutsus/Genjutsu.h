#ifndef GENJUTSU_H
#define GENJUTSU_H

#include <string>
#include <iostream>
#include "Jutsu.h"

// inherit from Jutsu
// Genjutsu eg Tsukuyomi etc mess with senses
class Genjutsu : public Jutsu {
public:
    std::string target_sense;
    double duration;

    Genjutsu(std::string n, double c, double d, std::string t, double dur);
    void display() override;

};


#endif
