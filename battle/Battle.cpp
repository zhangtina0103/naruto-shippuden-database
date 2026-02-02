#include "Battle.h"
#include "../Ninja.h"
#include "../sort/Sort.h"


void battleSimulation(Ninja a, Ninja b) {
    // start w/ 200 hps
    double hp1 = 200;
    double hp2 = 200;
    int round = 1;

    const std::vector<std::string> fields = {"strength", "speed", "chakra_level"};

    // set up the random number generator
    // use std::random_device to get a non-deterministic seed if available
    std::random_device rd;
    // use the Mersenne Twister engine for high-quality pseudo-random numbers
    std::mt19937 eng(rd());
    // define a uniform distribution for the valid index range [0, size - 1]
    std::uniform_int_distribution<size_t> distr(0, fields.size() - 1);

    while (hp1 > 0 && hp2 > 0) {
        // generate a random index and access the element
        size_t randomIndex = distr(eng);
        std::string randomField = fields[randomIndex];

        std::cout << "~~~~ round " << round << ": " << randomField << " scrimmage! ~~~~" << std::endl;

        double statA = getStat(a, randomField);
        double statB = getStat(b, randomField);
        std::cout << a.name << " (" << randomField << ": " << statA << ") " << "vs. " << b.name << " (" << randomField << ": " << statB << ") " <<std::endl;

        double damage = 10 + (abs(statA - statB) * 0.5);  // base damage + stat difference

        if (statA > statB) {
            hp2 -= damage;
            std::cout << a.name << " wins the round! " << b.name << " takes " << damage << " damage ~" << std::endl;
        } else {
            hp1 -= damage;
            std::cout << b.name << " wins the round! " << a.name << " takes " << damage << " damage ~" << std::endl;
        }

        std::cout << a.name << " HP: " << hp1 << " | " << b.name << " HP: " << hp2 <<std::endl;
        round++;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // when someone loses
    if (hp1 <= 0) {
        std::cout << b.name << " wins the battle ~" << std::endl;
    } else if (hp2 <= 0) {
        std::cout << a.name << " wins the battle ~" << std::endl;
    } else {
        std::cout << "no winners ~" << std::endl;
    }
}
