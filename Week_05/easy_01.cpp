// 70. 爬楼梯

using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2 || n == 3) return n;
        int a = 1, b = 2, c = 3;

        for (int i = 3; i < n; i++) {
            a = b; b = c; c = a + b;
        }

        return c;
    }
};

// 遍历一遍 n； 时间复杂度 O(n)
// 3 个变量； 空间复杂度 O(1)

