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
                    dfs(grid, i, j);
                    result++;
                }
            }
        }
        return result;
    }
    // 遍历一遍岛屿; 遇到岛屿就计数同时将该岛屿清零，调用多少次不好说呀这题？？？
    // 时间复杂度：O(n * m)

    // 只用了一个 int 变量，空间复杂度：O(1)

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (grid[row][col] != '1') return;

        grid[row][col] = '0';
        if (row - 1 >= 0  && grid[row - 1][col] == '1')
            dfs(grid, row - 1, col);
        if (row + 1 < grid.size() && grid[row + 1][col] == '1')
            dfs(grid, row + 1, col);
        if (col - 1 >= 0  && grid[row][col - 1] == '1')
            dfs(grid, row, col - 1);
        if (col + 1 < grid[0].size() && grid[row][col + 1] == '1')
            dfs(grid, row, col + 1);
    }
};