// 72. 编辑距离
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int row = word1.size(), col = word2.size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1));
        for (int i = 0; i <= col; i++) dp[0][i] = i;
        for (int i = 0; i <= row; i++) dp[i][0] = i;

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        }

        return dp[row][col];
    }
};
// 两层循环 时间复杂度：O(m * n)
// 二维矩阵 空间复杂度：O(m * n)