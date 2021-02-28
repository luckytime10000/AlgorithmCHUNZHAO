// 22. 括号生成
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> result;
    string tmp = "";
    vector<string> generateParenthesis(int n) {
        dfs(n, n);
        return result;
    }
    void dfs(int left, int right) {
        if (left == 0 && right == 0) {
            result.emplace_back(tmp);
            return;
        }
        if (left > 0) {
            tmp += "(";
            dfs(left - 1, right);
            tmp.pop_back();
        }
        if (right > left) {
            tmp += ")";
            dfs(left, right - 1);
            tmp.pop_back();
        }
    }
};

