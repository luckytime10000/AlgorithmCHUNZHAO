// 221. 最大正方形
#include <vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        // dp[i][j] 表示以 i j 为右下角的正方形的最大边长
        int result = 0;
        for (int i = 0; i < matrix.size(); i++) {
            dp[i][0] = matrix[i][0] - '0';
            if (dp[i][0] > result) result = dp[i][0];

        }
        for (int j = 0; j < matrix[0].size(); j++) {
            dp[0][j] = matrix[0][j] - '0';
            if (dp[0][j] > result) result = dp[0][j];
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                    if (dp[i][j] > result) result = dp[i][j];
                }
            }
        }

        return result * result;
    }
};
// 两层循环 时间复杂度：O(m * n)
// 二维数组 空间复杂度：O(m * n)
