// 122. 买卖股票的最佳时机 II
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int index = 0, result = 0, psize = prices.size();
        bool buy = false;

        // 依次找下一个最小值买入，最大值卖出
        while (index < psize) {
            if (getNextMinIndex(prices, index)) {
                result -= prices[index];    // 买入 扣钱
                buy = true;     // 买入操作完成
            }else break;
            if (getNextMaxIndex(prices, index)) {
                result += prices[index];    // 卖出 收钱
                buy = false;    // 卖出操作完成
            }else break;
        }
        if (buy) result += prices[psize-1];     // 最后买入操作, 按最后价格卖出收钱
        return result;
    }
    // 遍历一遍 prices; 时间复杂度 O(n)
    // 三个 int 变量， 1 个 bool 变量; 空间复杂度 O(1)

    // 获取下一个最大值的下标
    bool getNextMaxIndex(vector<int>& prices, int& index) {
        if (index + 1 == prices.size()) return false;   // 当前已经是最后一天，无下一天
        while (index + 1 < prices.size()) {
            if (prices[index + 1] >= prices[index]) index++;
            else return true;
        }
        return true;
    }

    // 获取下一个最小值的下标
    bool getNextMinIndex(vector<int>& prices, int& index) {
        if (index + 1 == prices.size()) return false;
        while (index + 1 < prices.size()) {
            if (prices[index + 1] <= prices[index]) index++;
            else return true;
        }
        return true;
    }
};