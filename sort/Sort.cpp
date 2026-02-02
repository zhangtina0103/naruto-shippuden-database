#include "Sort.h"

// implement quick sort for sorting
double getStat(Ninja& ninja, std::string field) {
    if (field == "chakra_level") return ninja.chakra_level;
    if (field == "strength") return ninja.strength;
    if (field == "speed") return ninja.speed;
    return 0;
}


bool compare(Ninja& a, Ninja& b, std::string field) {
    if (field == "name") return a.name <= b.name;
    if (field == "village") return a.village <= b.village;
    if (field == "clan") return a.clan <= b.clan;
    return getStat(a, field) <= getStat(b, field);
}

int partition(std::vector<Ninja>& ninjas, int low, int high, std::string field) {
    int i = low - 1;  // index of smaller element

    for (int j = low; j < high; j++) {
        if (compare(ninjas[j], ninjas[high], field)) {
            i++;
            std::swap(ninjas[i], ninjas[j]);
        }
    }
    std::swap(ninjas[i + 1], ninjas[high]);
    return i + 1;
}

void quicksort(std::vector<Ninja>& ninjas, int low, int high, std::string field) {
    if (low < high) {
        int pivotIndex = partition(ninjas, low, high, field);
        quicksort(ninjas, low, pivotIndex - 1, field);
        quicksort(ninjas, pivotIndex + 1, high, field);
    }
}
