// 78. 子集
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return result;
        dfs(nums, 0);
        return result;
    }

    void dfs(vector<int>& nums, int index) {
        if (index == nums.size()) {
            result.emplace_back(path);
            return;
        }

        path.emplace_back(nums[index]);     // 加入当前数字
        dfs(nums, index + 1);
        path.pop_back();        // 不加入当前数字
        dfs(nums, index + 1);
    }

    // 每个位置都要两种形态递归调用，所以调用 2 ^ n 次; 时间复杂度 O(2 ^ n)
    // 固定 result 和 path 两个变量，每次调用到最后都要加入 result 中;
    // 空间复杂度： O(2 ^ n)
};