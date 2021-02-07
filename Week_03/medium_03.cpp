// 17. 电话号码的字母组合
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> result;
    string path;
    vector<string> letter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return result;
        dfs(digits, 0);
        return result;
    }

    void dfs(string digits, int index) {
        if (path.size() == digits.size()) { // 递归出口
            result.emplace_back(path);
            return;
        }

        int newIndex = digits[index] - '2'; // 当前数字对应字母表的下标
        for (int i = 0; i < letter[newIndex].size(); i++) {  // 当前数字对应可能的字母
            path += letter[newIndex][i];
            dfs(digits, index + 1);
            path.pop_back();
        }
    }

    // 每个位置有3 或 4种可能，所以调用 3 ^ n -> 4 ^ n 之间的次数; 时间复杂度：O(4 ^ n)
    // 深度优先，每次最后都要放入 result 中; 空间复杂度：O(4 ^ n)
};