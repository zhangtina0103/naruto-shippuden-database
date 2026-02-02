#ifndef JUTSU_H
#define JUTSU_H

#include <string>
#include <iostream>

// inherit from Ninja
class Jutsu {
public:
    std::string name;
    double chakra_cost;
    double difficulty;

    Jutsu(std::string n, double c, double d);
    virtual void display();
};


#endif
