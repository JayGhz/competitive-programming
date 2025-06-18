#include <functional>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    vector<string> result;
    TrieNode *root = new TrieNode();

    for (const string &word : wordDict) {
      insert(root, word);
    }

    // Función auxiliar para backtracking
    function<void(string &, int, string)> backtrack = [&](string &s, int start, string current) {
      if (start >= s.length()) {
        if (!current.empty()) {
          // Eliminar el espacio extra al final
          current.pop_back();
          result.push_back(current);
        }
        return;
      }

      
      string word;
      TrieNode *node = root;

      for (int i = start; i < s.length(); i++) {
        word += s[i];

        // Verificar si el prefijo actual existe en el Trie
        if (node->children.find(s[i]) != node->children.end()) {
          node = node->children[s[i]];

          // Si es una palabra válida, intentar la siguiente segmentación
          if (node->isEnd) {
            backtrack(s, i + 1, current + word + " ");
          }
        } else {
          break;
        }
      }
    };

    backtrack(s, 0, "");
    return result;
  }

  struct TrieNode {
    bool isEnd;
    std::map<char, TrieNode *> children;

  public:
    TrieNode() : isEnd(false) {}
  };

  void insert(TrieNode *root, std::string word) {
    TrieNode *node = root;
    for (char c : word) {
      if (node->children.find(c) == node->children.end()) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->isEnd = true;
  }

  bool find(TrieNode *root, std::string word) {
    TrieNode *node = root;
    for (char c : word) {
      if (node->children.find(c) == node->children.end() ||
          !node->children[c]) {
        return false;
      }
      node = node->children[c];
    }
    return true;
  }
};