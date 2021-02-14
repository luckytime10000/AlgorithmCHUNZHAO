// 64. 最小路径和
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        vector<int> dp(col + 1);

        dp[0] = 2147483647;
        dp[1] = grid[0][0];
        for (int i = 2; i <= col; i++) {    // 第一行累加
            dp[i] = grid[0][i - 1] + dp[i - 1];
        }

        for (int i = 1; i < row; i++) {
            for (int j = 1; j <= col; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j-1];
            }
        }

        return dp[col];
    }
};
// 两层循环 时间复杂度：O(m * n)
// 空间复杂度：O(n)