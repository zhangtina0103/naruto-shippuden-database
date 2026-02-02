#include "BST.h"

BST::BST(std::string f) : root(nullptr), field(f) {};

double BST::getStat(Ninja& ninja) {
    if (field == "chakra_level") return ninja.chakra_level;
    if (field == "strength") return ninja.strength;
    if (field == "speed") return ninja.speed;
    return 0;
}

//insert into BST
Node* BST::insert(Node* node, Ninja ninja) {
    // base case: if no node in tree
    if (node == nullptr) {
        return new Node(ninja);
    } else if (getStat(node->ninja) >= getStat(ninja)) {
        node->left = insert(node->left, ninja);
    } else {
        node->right = insert(node->right, ninja);
    }
    return node;
}

//search and return pter node with specific id
Node* BST::search(Node* node, double value) {
    if (node == nullptr) {
        std::cout << "no ninja with this chakra level found ~" << std::endl;
        return nullptr;
    }
    // base case: if current node has value, then return node
    if (getStat(node->ninja) == value) {
        return node;
    } else if (getStat(node->ninja) > value) { //ow search left if value lower than current
        return search(node->left, value);
    } else { //search right if value higher than current
        return search(node->right, value);
    }
}

void BST::traverse(Node* node, bool ascending) {
    if (ascending) {
        // base case: no node
        // traverse left then self then right
        if (node == nullptr) return;
        traverse(node->left, ascending);
        std::cout << node->ninja.name << " | " << getStat(node->ninja) << std::endl;
        traverse(node->right, ascending);
    } else {
        if (node == nullptr) return;
        traverse(node->right, ascending);
        std::cout << node->ninja.name << " | " << getStat(node->ninja) << std::endl;
        traverse(node->left, ascending);
    };
}

Node* BST::findMax(Node* node) {
    // base case: if current node has no right children
    if (node->right == nullptr) {
        return node;
    } else { //keep traversing right
        return findMax(node->right);
    }
}
Node* BST::findMin(Node* node) {
    // base case: if current node has no left children
    if (node->left == nullptr) {
        return node;
    } else { //keep traversing left
        return findMin(node->left);
    }
}

void BST::insert(Ninja ninja) {
    root = insert(root, ninja);
}

Node* BST::search(double value) {
    return search(root, value);
}

void BST::traverse(bool ascending) {
    traverse(root, ascending);
}

Node* BST::findMax() {
    return findMax(root);
}

Node* BST::findMin() {
    return findMin(root);
}
