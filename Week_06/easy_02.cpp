// 242. 有效的字母异位词
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> v1(26, 0), v2(26, 0);
        for (int i = 0; i < s.size(); i++) {
            v1[s[i] - 'a']++;
            v2[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) if (v1[i] != v2[i]) return false;
        return true;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(1)