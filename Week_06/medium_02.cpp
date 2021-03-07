// 91. 解码方法
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, result = 1, tmp = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') {   // 10 20
                    tmp = pre;  // dp[n - 2]
                } else return 0;    // 没得解释
            } else {
                if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7') { // 11 -19 21 - 26
                    tmp = result + pre;     // dp[n - 1] + dp[n - 2]
                }
            }
            pre = result;
            result = tmp;
        }
        return result;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)

