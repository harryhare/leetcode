#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool search(vector<vector<char>> &board, int i, int j, const string &word) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m) {
            return false;
        }
        if (j < 0 || j >= n) {
            return false;
        }
        char c = word[0];
        if (board[i][j] != c) {
            return false;
        }
        if (word.size() == 1) {
            return true;
        }
        string subword = word.substr(1);
        board[i][j] = 0;
        if (search(board, i - 1, j, subword))return true;
        if (search(board, i + 1, j, subword))return true;
        if (search(board, i, j - 1, subword))return true;
        if (search(board, i, j + 1, subword))return true;
        board[i][j] = c;
        return false;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (search(board, i, j, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    string x = "123";
    cout << x.substr(1) << endl;

    vector<vector<char>> board={{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    Solution s;
    cout<<s.exist(board,word)<<endl;
}