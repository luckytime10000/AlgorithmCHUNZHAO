// 200. 岛屿数量
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }

        return result;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (grid[i][j] == '0') return;

        grid[i][j] = '0';
        if (i - 1 >= 0) dfs(grid, i - 1, j);
        if (j - 1 >= 0) dfs(grid, i, j - 1);
        int row = grid.size(), col = grid[0].size();
        if (i + 1 < row) dfs(grid, i + 1, j);
        if (j + 1 < col) dfs(grid, i, j + 1);
    }
};