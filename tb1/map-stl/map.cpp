#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> nodohijo;
    string word = "";
};

class Solution {
    vector<string> result;
    int fil, col;

    void insert(TrieNode* raiz, const string& pal) {
        TrieNode* node = raiz;
        for (char c : pal) 
        {
            if (!node->nodohijo.count(c))
            {
                node->nodohijo[c] = new TrieNode();
            }
            node = node->nodohijo[c];
        }
        node->word = pal;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* nodo) {
        char c = board[i][j];
        if (!nodo->nodohijo.count(c)) return;
        nodo = nodo->nodohijo[c];
        if (!nodo->word.empty()) {
            result.push_back(nodo->word);
            nodo->word.clear();
        }
        board[i][j] = 'x';
        vector<pair<int, int>> dirs = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        for (const auto& dir : dirs) 
        {
            int dx = dir.first, dy = dir.second;
            int ni = i + dx, nj = j + dy;
            if (ni >= 0 && ni < fil && nj >= 0 && nj < col && board[ni][nj] != 'x') {
                dfs(board, ni, nj, nodo);
            }
        }
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* raiz = new TrieNode();
        for (const string& pal : words)
        {
           insert(raiz, pal);
        }
        fil = board.size();
        col = board[0].size();
        for (int i = 0; i < fil; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
               dfs(board, i, j, raiz);
            }
        }
        return result;
    }
};
