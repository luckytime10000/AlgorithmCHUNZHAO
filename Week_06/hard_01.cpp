// 32. 最长有效括号
#include <iostream>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, result = 0;
        for (int i = 0; i < s.size(); i++) {    // 从左往右扫描
            s[i] == '(' ? left++ : right++;
            if (left > right) continue;
            if (left == right) result = max(result, right);
            else {
                left = 0; right = 0;
            }
        }
        left = 0; right = 0;
        for (int i = s.size() - 1; i >= 0 ; i--) {    // 从右往左扫描
            s[i] == '(' ? left++ : right++;
            if (left < right) continue;
            if (left == right) result = max(result, left);
            else {
                left = 0; right = 0;
            }
        }


        return result * 2;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)