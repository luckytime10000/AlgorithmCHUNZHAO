// 74. 搜索二维矩阵
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int tall = matrix.size();   // 矩阵行数
        int width = matrix[0].size();   // 矩阵列数
        int left = 0, right = tall * width - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            int mid_row = mid / width, mid_col = mid % width;
            int val = matrix[mid_row][mid_col];

            if (val == target) {
                return true;
            }else if (target < val) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return false;
    }
    // 二分查找，时间复杂度：O(log(n))
    // 二分查找中用了 4 个 int 变量; 空间复杂度：O(log(n))
};