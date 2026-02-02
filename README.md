## Naruto database

A C++ database application for managing ninja and jutsu data in Naruto Shippuden, which is one of my childhood favorite animes! This got me to work with BSTs, sorting algorithms, multithreading, and file handling!

### features
- basic operations: add, remove, update, search ninjas and jutsu
- SQLite database: storage with junction tables for many-to-many ninja-jutsu relationships
- binary search tree: BST for ranking ninjas by any numeric stat (chakra level, speed, strength)
- quicksort: sort ninjas by any field including alphabetical sorting
- multithreaded battle simulator: background battle simulation comparing ninja stats round-by-round
- file handling: import/export ninja data through csv

### languages/tooling
- C++17
- SQLite3
- STL (vectors, threads, random, fstream, sstream)

### build and run
```bash
g++ -std=c++17 main.cpp Ninja.cpp Database.cpp bst/BST.cpp sort/Sort.cpp battle/Battle.cpp fileHandler/FileHandler.cpp jutsus/Jutsu.cpp jutsus/Ninjutsu.cpp jutsus/Genjutsu.cpp jutsus/Taijutsu.cpp -lsqlite3 -pthread -o main
./main
```
