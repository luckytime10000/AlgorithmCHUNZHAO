// 300. 最长递增子序列
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int result = 0;
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i]++;    // 加上自己本身
            if (dp[i] > result) result = dp[i];
        }
        return result;  // 返回dp数组中的最大值，不是dp[n]
    }
};
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)