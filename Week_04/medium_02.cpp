// 91. 解码方法
#include <iostream>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0') return 0;
        int pre = 1, cur = 1, tmp;  // 初值是 1

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == '0') {
                if (s[i - 1] == '1' || s[i - 1] == '2') // 10, 20
                    tmp = pre;  // 回退到上一格的值， 10 20 只能合在一起翻译一种
                else return 0;  // 30 40 ... 90 00
            } else {    // 个位 1 - 9
                // 11 - 19  21 - 26
                if (s[i - 1] == '1' || s[i-1] == '2' && s[i] > '0' && s[i] < '7')
                    tmp = pre + cur;
            }
            // 遇到 27 以上时，直接延续上一次的值
            pre = cur;
            cur = tmp;
        }

        return cur;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)

