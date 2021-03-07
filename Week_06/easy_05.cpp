// 151. 翻转字符串里的单词
#include <iostream>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 0) return s;
        int left = 0, right = s.size() - 1;
        string result;

        while (true) {
            while (right >= 0 && s[right] == ' ') right--;   // 到 -1 说明没有单词了
            if (right < 0) break;
            left = right - 1;
            while (left >= 0 && s[left] != ' ') left--;     // 到 -1 说明这个单词从 0 开始
            for (int i = left + 1; i <= right; i++) result += s[i];
            result += " ";
            right = left - 1;
        }

        result.pop_back();
        return result;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)