#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <map>

struct TrieNode {
    bool isEnd;
    std::map<char, TrieNode*> children;

    public:
    TrieNode() : isEnd(false) {}


};


void insert(TrieNode* root, std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end()) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
    }
    node->isEnd = true;
}

bool find(TrieNode* root, std::string word) {
    TrieNode* node = root;
    for (char c : word) {
        if (node->children.find(c) == node->children.end() || !node->children[c]) {
            return false;
        }
        node = node->children[c];
    }
    return true;
}

#endif