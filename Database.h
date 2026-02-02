#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>
#include <iostream>

class Database {
public:
    sqlite3* db;

    //open db
    Database(std::string filename);
    //close db
    ~Database();

    //for running SQL commands
    void execute(std::string sql);
    void createTables();
    void searchNinja(std::string field, std::string value);
    void searchJutsu(std::string field, std::string value);


    void addJutsu(std::string name, double chakra_cost, double difficulty,
                        std::string jutsu_type, std::string element = "",
                        std::string target_sense = "", double duration = 0.0,
                        std::string combat_style = "");
    void addNinja(std::string name, std::string village, double chakra_level, std::string clan, double strength, double speed, std::string rank);
    void removeNinja(int id);
    void removeJutsu(int id);
    void updateNinja(std::string field, std::string new_value, std::string where_field, std::string where_value);
    void updateJutsu(std::string field, std::string new_value, std::string where_field, std::string where_value);
    void displayNinjas();
    void displayJutsus();

    void linkNinjaJutsu(int ninja_id, int jutsu_id);
};



#endif
