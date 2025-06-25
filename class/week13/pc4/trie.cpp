#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

// Creacion del nodo
struct TrieNode {
    bool isEnd;
    std::map<char, TrieNode*> children;

    public:
    TrieNode() : isEnd(false) {}


};

// Funcion de insercion
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

// Funcion de busqueda
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

// Funcion auxiliara para contar palabras con el prefijo
int countPrefix(TrieNode* root, const std::string& prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (node->children.find(c) == node->children.end()) {
            return 0;
        }
        node = node->children[c];
    }
    int count = 0;
    std::vector<TrieNode*> stack = {node};
    while (!stack.empty()) {
        TrieNode* curr = stack.back();
        stack.pop_back();
        if (curr->isEnd) count++;
        for (auto& p : curr->children) {
            stack.push_back(p.second);
        }
    }
    return count;
}

// Funcion auxiliar para verificar si una palabra es valida
bool isAlpha(const std::string& s) {
    // validamos que la cadena tenga entre 1 y 20 caracteres
    if (s.empty() || s.size() > 20) return false;
    for (char c : s) {
        if (!isalpha(c)) return false;
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    TrieNode* root = new TrieNode();
    set<string> inventory;
    string op, prod;
    while (cin >> op >> prod) {
        if (!isAlpha(prod)) continue;
        if (op == "a") {
            if (inventory.find(prod) == inventory.end()) {
                insert(root, prod);
                inventory.insert(prod);
            }
        } else if (op == "b") {
            int res = countPrefix(root, prod);
            cout << res << endl;
        }
    }
    return 0;
}