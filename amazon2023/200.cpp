#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        int n1 = grid.size();
        int n2 = grid[0].size();
        if (i < 0 || i >= n1) {
            return;
        }
        if (j < 0 || j >= n2) {
            return;
        }
        if (grid[i][j] != '1') {
            return;
        }
        grid[i][j] = 2;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }

    int numIslands(vector<vector<char>> &grid) {
        int n1 = grid.size();
        int n2 = grid[0].size();
        int island = 0;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    dfs(grid, i, j);
                }
            }
        }
        return island;
    }
};