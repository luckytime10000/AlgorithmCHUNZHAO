// 55. 跳跃游戏
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int location = nums.size() - 1; // 终点

        for (int i = location; i >= 0; i--) {
            if (nums[i] + i >= location) location = i;  // 当前位置可以跳到终点，更新终点
        }

        return location == 0;
    }

    // 遍历一遍nums ; O(n)
    // 用了1 个 int 变量; O(1)
};