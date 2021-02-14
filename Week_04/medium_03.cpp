// 621. 任务调度器
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0) return tasks.size();

        int size = tasks.size();
        int result = 1;
        vector<int> count(26);  // 统计任务次数
        for (auto &ele: tasks) count[ele - 'A']++;
        sort(count.begin(), count.end());   // 按任务次数排序      O(n log(n))
        int maxNum = count[25];     // 任务最多的次数
        for (int i = 24; i >= 0; i--) {     // 从后往前，并列最多时 result 自加
            if (count[i] == maxNum) result++;
            else break;
        }

        result += (maxNum - 1) * (n + 1);   // 前面必须的冷却时间
        return result > size ? result : size;
    }
};
// 时间复杂度：O(n log(n))
// 空间复杂度：O(1)