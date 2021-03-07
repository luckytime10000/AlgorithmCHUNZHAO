// 387. 字符串中的第一个唯一字符
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for (int i = 0; i < s.size(); i++) v[s[i] - 'a']++;
        for (int i = 0; i < s.size(); i++) if (v[s[i] - 'a'] == 1) return i;
        return -1;
    }
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
