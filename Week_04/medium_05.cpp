// 647. 回文子串
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() < 2) return s.size();
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        // dp[i][j] 表示从下标 i 到 j 是否时回文子串

        for (int j = 0; j < s.size(); j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    result++;
                }
            }
        }

        return result;
    }
};
// 两层循环 时间复杂度：O(n ^ 2)
// 二维数组 空间复杂度：O(n ^ 2)