#include "trie.h"
#include <iostream>


int main() {
    TrieNode* root = new TrieNode();
    insert(root, "eduardo");
    std::cout << find(root, "edu") << std::endl;
    std::cout << find(root, "edupa") << std::endl;
    std::cout << find(root, "eduardo") << std::endl;
}
