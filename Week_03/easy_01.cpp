// 169. 多数元素
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        unordered_map<int, int> map;    // 记录数字与其出现的次数
        int result;
        int num = 0;
        for (auto &ele: nums) {
            if (++map[ele] > num) {    // 每次记录都判断与当前出现最多的次数比较
                num = map[ele];
                result = ele;
            }
        }
        return result;
    }
};

// 遍历一遍 nums 数组
// map 记录 nums 不重复的数字，最差情况记录所有
// 时间复杂度 O(n)
// 空间复杂度 O(n)

