#include <vector>
#include "../Ninja.h"

void quicksort(std::vector<Ninja>& ninjas, int low, int high, std::string field);
int partition(std::vector<Ninja>& ninjas, int low, int high, std::string field);
double getStat(Ninja& ninja, std::string field);
