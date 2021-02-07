// 860. 柠檬水找零
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;  // 5 10 20 美元的数量
        for (auto &ele: bills) {    // 遍历账单
            if(ele == 5) five++;    // 5 美元直接收
            else if(ele == 10) {    // 10 美元，收 10 找 5
                ten++;
                five--;
            }else {     // 20 美元  收 20 找 (10 + 5) 或者 （5 * 3）
                twenty++;
                ten--; five--;
                if (ten < 0) {  // 没得 10 美元找 换 3 张 5 美元
                    ten++;
                    five -= 2;
                }
            }

            if (five < 0 || ten < 0) return false;
        }
        return true;
    }
};

// 遍历一遍账单 时间复杂度 O(n)
// 用三个 int 变量  空间复杂度 O(1)