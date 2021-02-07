// 50. Pow(x, n)
#include <iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (x == 1 || x == 0 || n == 1) return x;
        if (n == -1) return 1 / x;
        if (n == 0) return 1;


        double half = myPow(x, n / 2);

        if (n % 2 == 0) return half * half;
        else if (n > 0) return half * half * x;
        else return half * half * (1 / x);
    }

    // 每次都任务减半; 时间复杂度：O(log(n))
    // 需要 O(log(n)) * 1 个 double 变量; 空间复杂度：O(log(n))
};