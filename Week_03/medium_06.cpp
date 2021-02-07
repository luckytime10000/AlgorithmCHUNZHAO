// 529. 扫雷游戏
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.size() == 0) return board;
        int row = click[0], col = click[1];

        // 直接挖雷
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
            return board;
        }
        dfs(board, row, col);
        return board;
    }

    // 深度优先，最坏情况访问整个矩阵; O(m * n)
    // dfs中用了常量个变量 ; O(m * n)

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (board[row][col] != 'E') return; // 处理过
        int num = getNumber(board, row, col);
        if (num != 0) {     // 当前位置周围有炸弹则停止 dfs
            board[row][col] = '0' + num;
            return;
        }

        int tall = board.size(), width = board[0].size();
        board[row][col] = 'B';
        if (row - 1 >= 0 ) { // 上一行
            if (col-1 >= 0) dfs(board, row - 1, col - 1);   // 左上角
            dfs(board, row - 1, col);   // 上
            if (col+1 < width) dfs(board, row - 1, col + 1);   // 右上角

        }
        {   // 当前行
            if (col - 1 >= 0) dfs(board, row, col - 1); // 左
            if (col + 1 < width) dfs(board, row, col + 1); // 右
        }
        if (row + 1 < tall) {   // 下一行
            if (col-1 >= 0) dfs(board, row + 1, col - 1);   // 左下角
            dfs(board, row + 1, col);   // 下
            if (col+1 < width) dfs(board, row + 1, col + 1);   // 右下角
        }
    }

    // 获取当前位置周围的炸弹数量
    int getNumber(vector<vector<char>>& board, int row, int col) {
        int result = 0;
        for (int i = row - 1; i <= row + 1; i++) {
            for (int j = col - 1; j <= col + 1; j++) {
                if (i >= 0 && i < board.size() && j >= 0 && j < board[0].size()) {
                    if (board[i][j] == 'M')
                        result++;
                }
            }
        }
        return result;
    }
};