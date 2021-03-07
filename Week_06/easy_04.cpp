// 541. 反转字符串 II
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size() < 2 || k < 2) return s;
        int i = 0, lens = s.size(), left = 0, right = min(k - 1, lens - 1);
        while (true) {
            while (left < right) swap(s[left++], s[right--]);
            i += k * 2;
            if (lens - i < 2) break;    // 剩余少于 2 个
            left = i; right = min(i + k - 1, lens - 1);
        }
        return s;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)