// 45. 跳跃游戏 II
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, result = 0;
        int target = nums.size() - 1;   // 目标位置

        while (end < target) {  // 当前可跳的最远距离没到目标位置时
            result++;
            int right = end;    // 当前一轮可以跳到的最远距离
            for (int i = start; i <= end; i++) {
                right = (i + nums[i] > right) ? i + nums[i] : right;
            }
            start = end + 1;
            end = right;
        }
        return result;
    }
    // 遍历一轮 nums ; 时间复杂度：O(n)
    // 循环外 4 个 int 变量， 循环内 1 个 int 变量; 空间复杂度：O(n)
};