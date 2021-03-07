// 917. 仅仅反转字母
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        if (S.size() < 2) return S;
        string result = S;
        int left = 0, right = S.size() - 1;

        while (true) {
            while (left < right && !isLetter(result[left])) left++;
            while (right > left && !isLetter(result[right])) right--;
            if (left >= right) break;       // 中间相邻相遇后会使 left > right
            swap(result[left++], result[right--]);
        }
        return result;
    }
    bool isLetter(char c) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') return true;
        return false;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)