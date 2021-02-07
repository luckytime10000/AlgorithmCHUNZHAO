// 51. N 皇后
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) return result;
        vector<bool> col(n);    // 默认值为  false
        vector<bool> dg(n * 2);  // 对应 row + col
        vector<bool> adg(n * 2);  // 对应 row - col + n
        dfs(0, n, col, dg, adg);
        return result;
    }

    // 时间复杂度看不出来
    // 结果集需要存储整个棋盘(n * n * 可行方案数)  ; 时间复杂度：O(n ^ 2)

    void dfs(int r, int n, vector<bool> &col, vector<bool> &dg, vector<bool> &adg){
        if (r == n) {
            result.emplace_back(path);
            return;
        }

        // 当前行每一列查找合法位置
        for (int i = 0; i < n; i++) {
            if (!col[i] && !dg[r + i] && !adg[r - i + n]) { // 当前位置不会被其它皇后攻击
                col[i] = true; dg[r+i] = true; adg[r-i+n] = true;
                string tmp = string(n, '.');  tmp[i] = 'Q';
                path.emplace_back(tmp);

                dfs(r+1, n, col, dg, adg);

                col[i] = false; dg[r+i] = false; adg[r-i+n] = false;
                path.pop_back();
            }
        }
    }
};