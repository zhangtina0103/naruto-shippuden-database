#include <iostream>
#include <string>
#include "../Ninja.h"

//define node struct
struct Node {
    Ninja ninja;
    Node* left; //pointer to a node (hold memory addrss of another node or nullptr if no child there)
    Node* right;
    Node(Ninja n) : ninja(n), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;
    Node* search(Node* node, double chakra_level);
    Node* findMax(Node* node);
    Node* findMin(Node* node);
    Node* insert(Node* node, Ninja ninja);
    void traverse(Node* node, bool ascending = true);

public:
    //initialize with empty tree
    BST(std::string f);
    std::string field; //field to sort by)
    double getStat(Ninja& ninja);

    //insert ninja into BST
    void insert(Ninja ninja);

    //search and return node with specific id
    Node* search(double value);

    //inorder traversals
    void traverse(bool ascending = true);

    Node* findMax();
    Node* findMin();
};
