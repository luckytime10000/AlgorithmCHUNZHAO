// 231. 2的幂

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? !(n & (n - 1)) : false;
    }
};

// 没有遍历，时间复杂度：O(1)
// 空间复杂度：O(1)