#include <fstream>
#include <vector>
#include <iostream>
#include "../Ninja.h"
#include <sstream>

void exportNinjas(std::vector<Ninja*> ninjas, std::string file_name);
std::vector<Ninja> importNinjas(std::vector<Ninja*> ninjas, std::string file_name);
