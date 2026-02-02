#include "Database.h"

Database::Database(std::string file_name) {
    int result = sqlite3_open(file_name.c_str(), &db);
    if (result) {
        std::cerr << "can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "database opened ~" << std::endl;
    }
}

Database::~Database() {
    sqlite3_close(db);
    std::cout << "database closed ~" << std::endl;
}

void Database::execute(std::string sql) {
    char* errMsg;
    int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "success ~" << std::endl;
    }
}

void Database::createTables() {
    // only create if table doesn't exist yet
    std::string sql = R"(
        CREATE TABLE IF NOT EXISTS ninjas (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        village TEXT,
        chakra_level REAL,
        clan TEXT,
        strength REAL,
        speed REAL,
        rank TEXT
        );

        CREATE TABLE IF NOT EXISTS jutsus (
        id INTEGER PRIMARY KEY AUTOINCREMENT,
        name TEXT NOT NULL,
        chakra_cost REAL,
        difficulty REAL,
        jutsu_type TEXT,
        element TEXT,
        target_sense TEXT,
        duration REAL,
        combat_style TEXT
        );

        CREATE TABLE IF NOT EXISTS ninja_jutsu (
        ninja_id INTEGER,
        jutsu_id INTEGER,
        FOREIGN KEY (ninja_id) REFERENCES ninjas(id),
        FOREIGN KEY (jutsu_id) REFERENCES jutsus(id)
        );
    )";

    char* errMsg;
    int result = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);

    if (result != SQLITE_OK) {
        std::cerr << "error creating tables: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "tables ready ~" << std::endl;
    }
}


void Database::displayNinjas() {
    std::string sql = "SELECT * FROM ninjas;";

    sqlite3_stmt* stmt;  // prepared statement
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    std::cout << "\n=== all ninjas ~ ====" << std::endl;

    // loop through each row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        const char* village = (const char*)sqlite3_column_text(stmt, 2);
        double chakra_level = sqlite3_column_double(stmt, 3);
        const char* clan = (const char*)sqlite3_column_text(stmt, 4);
        double strength = sqlite3_column_double(stmt, 5);
        double speed = sqlite3_column_double(stmt, 6);
        const char* rank = (const char*)sqlite3_column_text(stmt, 7);

        std::cout << id << " | " << name << " | " << village << " | " << chakra_level << " | " << clan << " | " << strength << " | " << speed << " | " << rank << std::endl;
    }
    // cleanup
    sqlite3_finalize(stmt);
}

void Database::displayJutsus() {
    std::string sql = "SELECT * FROM jutsus;";

    sqlite3_stmt* stmt;  // prepared statement
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    std::cout << "\n=== all jutsus ~ ====" << std::endl;

    // loop through each row
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        double chakra_cost = sqlite3_column_double(stmt, 2);
        double difficulty = sqlite3_column_double(stmt, 3);
        const char* raw_jutsu_type = (const char*)sqlite3_column_text(stmt, 4);
        std::string jutsu_type = raw_jutsu_type ? raw_jutsu_type : "N/A";
        const char* raw_element = (const char*)sqlite3_column_text(stmt, 5);
        std::string element = raw_element ? raw_element : "N/A";
        const char* raw_target_sense = (const char*)sqlite3_column_text(stmt, 6);
        std::string target_sense = raw_target_sense ? raw_target_sense : "N/A";
        double duration = sqlite3_column_double(stmt, 7);
        const char* raw_combat_style = (const char*)sqlite3_column_text(stmt, 8);
        std::string combat_style = raw_combat_style ? raw_combat_style : "N/A";

        std::cout << id << " | " << name << " | " << chakra_cost << " | " << difficulty << " | " << jutsu_type << " | " << element << " | " << target_sense << " | " << duration << " | " << combat_style << std::endl;
    }
    // cleanup
    sqlite3_finalize(stmt);
}

void Database::addNinja(std::string name, std::string village, double chakra_level, std::string clan, double strength, double speed, std::string rank) {
    std::string sql = "INSERT INTO ninjas (name, village, chakra_level, clan, strength, speed, rank) VALUES ('"
                      + name + "', '"
                      + village + "', "
                      + std::to_string(chakra_level) + ", '"
                      + clan + "', "
                      + std::to_string(strength) + ", "
                      + std::to_string(speed) + ", '"
                      + rank + "');";
    execute(sql);
}

void Database::addJutsu(std::string name, double chakra_cost, double difficulty,
                        std::string jutsu_type, std::string element,
                        std::string target_sense, double duration,
                        std::string combat_style) {
    std::string sql = "INSERT INTO jutsus (name, chakra_cost, difficulty, jutsu_type, element, target_sense, duration, combat_style) VALUES ('"
                      + name + "', "
                      + std::to_string(chakra_cost) + ", "
                      + std::to_string(difficulty) + ", '"
                      + jutsu_type + "', '"
                      + element + "', '"
                      + target_sense + "', "
                      + std::to_string(duration) + ", '"
                      + combat_style + "');";
    execute(sql);
}

void Database::removeNinja(int id) {
    std::string sql = "DELETE FROM ninjas WHERE id = "
                      + std::to_string(id) + ";";
    execute(sql);
}

void Database::removeJutsu(int id) {
    std::string sql = "DELETE FROM jutsus WHERE id = "
                      + std::to_string(id) + ";";
    execute(sql);
}

void Database::updateNinja(std::string field, std::string new_value, std::string where_field, std::string where_value) {
    std::string sql = "UPDATE ninjas SET " + field + " = '" + new_value + "' WHERE " + where_field + " = '" + where_value + "';";
    execute(sql);
}

void Database::updateJutsu(std::string field, std::string new_value, std::string where_field, std::string where_value) {
    std::string sql = "UPDATE jutsus SET " + field + " = '" + new_value + "' WHERE " + where_field + " = '" + where_value + "';";
    execute(sql);
}

void Database::searchJutsu(std::string field, std::string value) {
    std::string sql = "SELECT * FROM jutsus WHERE " + field + " = '" + value + "';";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        double chakra_cost = sqlite3_column_double(stmt, 2);
        double difficulty = sqlite3_column_double(stmt, 3);

        std::cout << id << " | " << name << " | " << chakra_cost << " | " << difficulty << std::endl;
    }
    sqlite3_finalize(stmt);
}

void Database::searchNinja(std::string field, std::string value) {
    std::string sql = "SELECT * FROM ninjas WHERE " + field + " = '" + value + "';";

    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const char* name = (const char*)sqlite3_column_text(stmt, 1);
        const char* village = (const char*)sqlite3_column_text(stmt, 2);
        double chakra_level = sqlite3_column_int(stmt, 3);
        const char* clan = (const char*)sqlite3_column_text(stmt, 4);
        double strength = sqlite3_column_double(stmt, 5);
        double speed = sqlite3_column_double(stmt, 6);
        const char* rank = (const char*)sqlite3_column_text(stmt, 7);

        std::cout << id << " | " << name << " | " << village << " | " << chakra_level << " | " << clan << " | " << strength << " | " << speed << " | " << rank << std::endl;
    }
    sqlite3_finalize(stmt);
}

void Database::linkNinjaJutsu(int ninja_id, int jutsu_id) {
    std::string sql = "INSERT INTO ninja_jutsu (ninja_id, jutsu_id) VALUES ("
                      + std::to_string(ninja_id) + ", "
                      + std::to_string(jutsu_id) + ");";
    execute(sql);
}
