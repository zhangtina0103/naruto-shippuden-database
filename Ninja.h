#ifndef NINJA_H
#define NINJA_H

#include <string>
#include <iostream>

class Ninja {
public:
    std::string name;
    std::string village;
    double chakra_level;
    std::string clan;
    double strength;
    double speed;
    std::string rank; //genin, chunin, jonin, etc

    Ninja(std::string n, std::string v, double l, std::string c, double s, double d, std::string r);
    void display();
};


#endif
