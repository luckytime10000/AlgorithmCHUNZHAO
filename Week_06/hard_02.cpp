// 818. 赛车
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, 0);
        dp[1] = 1;
        int k = 2, s = 3;   // k 次连续加速到达 s

        for (int i = 2; i <= target; i++) {
            if (i == s) {
                dp[i] = k++;
                s = (s << 1) + 1;
            } else {
                dp[i] = k + 1 + dp[s - i];  // k 个加速到 s 后掉头加速
                for (int j = 0; j < k - 1; j++) {   // k - 1 个加速后掉头
                    dp[i] = min(dp[i], k + j + 1 + dp[i - (1 << (k-1)) + (1 << j)]);
                }
            }
        }

        return dp[target];
    }
};
// 时间复杂度：不太确定
// 空间复杂度：O(n)