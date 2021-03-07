// 205. 同构字符串
#include <iostream>
#include <map>

using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> m;
        for (int i = 0; i < s.size(); i++) {    // s 映射到 t
            if (!m.count(s[i])) m[s[i]] = t[i];
            else if (m[s[i]] != t[i]) return false;
        }
        m.clear();
        for (int i = 0; i < s.size(); i++) {    // t 映射到 s
            if (!m.count(t[i])) m[t[i]] = s[i];
            else if (m[t[i]] != s[i]) return false;
        }
        return true;
    }
};
// 时间复杂度：O(n)
// 空间复杂度：O(n)