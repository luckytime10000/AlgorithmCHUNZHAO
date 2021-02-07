// 33. 搜索旋转排序数组
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int end = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (target > nums[end]) {     // 在左半递增数组
                if (nums[mid] < nums[end] || nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            else {  // 在右半递增数组
                if (nums[mid] > nums[end] || nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }

            }
        }
        return -1;
    }
    // 二分查找，时间复杂度：O(log(n))
    // 二分查找中用了 1 个 int 变量; 空间复杂度：O(log(n))
};