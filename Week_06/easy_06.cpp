// 557. 反转字符串中的单词 III
#include <iostream>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string result = s;
        int left = 0, right, tmp, lens = s.size();

        while (left < s.size()) {
            // if (s[left] == ' ') left++; // 指向下一个单词的第一个字母
            right = left + 1;
            while (right < lens && s[right] != ' ') right++;    // 指向下一个空格, 末尾则指向数组外
            tmp = right;

            while (left < right) swap(result[left++], result[--right]);

            left = tmp + 1; // 下一个单词开头字母
        }

        return result;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)