#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode *> children;
    string word;

    void insert(const string &word, int i) {
        auto iter = children.find(word[i]);
        TrieNode *node = NULL;
        if (iter != children.end()) {
            node = iter->second;
        } else {
            node = new TrieNode();
            children[word[i]] = node;
        }
        if (i == word.size() - 1) {
            node->word = word;
        } else {
            node->insert(word, i + 1);
        }
    }
};


class Solution {
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root, set<string> &res) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m) {
            return;
        }
        if (j < 0 || j >= n) {
            return;
        }
        char c = board[i][j];
        auto iter = root->children.find(c);
        if (iter == root->children.end()) {
            return;
        }
        TrieNode *p = iter->second;
        if (!p->word.empty()) {
            res.insert(p->word);
            if(p->children.size()==0){
                root->children.erase(c);
                delete p;
                return;
            }
        }
        board[i][j] = '#';
        dfs(board, i - 1, j, p, res);
        dfs(board, i + 1, j, p, res);
        dfs(board, i, j - 1, p, res);
        dfs(board, i, j + 1, p, res);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
        //build tree
        TrieNode root;
        for (const string &word: words) {
            root.insert(word, 0);
        }
        //search
        int m = board.size();
        int n = board[0].size();
        set<string> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, &root, res);
            }
        }
        vector<string> res_vector;
        for (auto iter = res.begin(); iter != res.end(); iter++) {
            res_vector.push_back(*iter);
        }
        return res_vector;
    }
};

int main(){
    Solution s;
//    vector<vector<char>> board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
//    vector<string> words={"oath","pea","eat","rain"};
    vector<vector<char>> board={{'a','a'}};
    vector<string> words={"aa"};
    s.findWords(board,words);

    return 0;
}