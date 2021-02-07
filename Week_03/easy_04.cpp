// 455. 分发饼干
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index_g = 0, index_s = 0, result = 0;

        while (index_g < g.size() && index_s < s.size()) {
            if (g[index_g] <= s[index_s]) {
                result++;
                index_g++; index_s++;
            }else {
                index_s++;
            }
        }
        return result;
    }
// sort(); 遍历两个数组直到其中一个结束; 时间复杂度：O(nlog(n))
// 用了 3 个int 变量; 空间复杂度：O(1)

};