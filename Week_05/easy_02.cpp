// 191. 位1的个数
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        while (n != 0) {
            n = n & (n-1);
            result++;
        }
        return result;
    }
};

// 最坏情况遍历32位 时间复杂度 O(1)
// 1 个变量  空间复杂度 O(1)