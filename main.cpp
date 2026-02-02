#include "battle/Battle.h"
#include <thread>

int main() {
    Ninja naruto("Naruto Uzumaki", "Konoha", 95.0, "Uzumaki", 90.0, 85.0, "Jonin");
    Ninja sasuke("Sasuke Uchiha", "Konoha", 98.0, "Uchiha", 88.0, 92.0, "Jonin");

    std::thread battleThread(battleSimulation, naruto, sasuke);

    for (int i = 0; i < 5; i++) {
        std::cout << "[MAIN] Still browsing the database..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(800));
    }

    battleThread.join();
    return 0;
}
