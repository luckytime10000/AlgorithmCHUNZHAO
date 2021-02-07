// 153. 寻找旋转排序数组中的最小值
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size() - 1, end = nums.size() - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1]) return nums[mid + 1];
            if (nums[mid] > nums[end]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return nums[left];  // 不旋转时直接返回最小值
    }
    // 二分查找; O(log(n))
    // 循环外部 3 个 int 变量 循环内部 1 个 int 变量; O(log(n))
};