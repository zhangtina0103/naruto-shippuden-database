#include "FileHandler.h"

void exportNinjas(std::vector<Ninja>& ninjas, std::string file_name) {
    // open file for writing
    std::ofstream file(file_name);
    // write to it like cout
    file << "name,village,chakra_level,clan,strength,speed,rank" << std::endl;
    for (auto& ninja : ninjas) {
        file << ninja.name << "," << ninja.village << "," << ninja.chakra_level << "," << ninja.clan << "," << ninja.strength << "," << ninja.speed << "," << ninja.rank << std::endl;
    }
    file.close();
    std::cout << "processed " << ninjas.size() << " ninjas ~ exported to " << file_name << std::endl;
}

// convert csv file to ninjas
std::vector<Ninja> importNinjas(std::string file_name) {
    // open file for reading
    std::ifstream file(file_name);
    std::vector<Ninja> ninjas;
    std::string line;
    std::getline(file, line); //skip header line

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name, village, clan, rank;
        std::string chakra_str, strength_str, speed_str;

        std::getline(ss, name, ',');
        std::getline(ss, village, ',');
        std::getline(ss, chakra_str, ',');
        std::getline(ss, clan, ',');
        std::getline(ss, strength_str, ',');
        std::getline(ss, speed_str, ',');
        std::getline(ss, rank, ',');

        Ninja ninja(name, village, std::stod(chakra_str), clan, std::stod(strength_str), std::stod(speed_str), rank);
        ninjas.push_back(ninja);
    }
    std::cout << "processed " << ninjas.size() << " ninjas ~ created vector" << std::endl;
    return ninjas;
}
