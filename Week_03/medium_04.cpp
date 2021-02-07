// 127. 单词接龙
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // 广度优先
        unordered_set<string> WordList(wordList.begin(), wordList.end());
        // 字典放入 set
        unordered_set<string> visited;  // 存放访问过的单词
        int step = 1, wordSize = beginWord.size();

        queue<string> que;
        que.emplace(beginWord);
        visited.emplace(beginWord);

        while (!que.empty()) {
            int curSize = que.size();   // 当前层次的队伍数量，用于按层次处理

            for (int i = 0; i < curSize; i++) {    // 当前层每一个单词
                string s = que.front();
                que.pop();

                for (int j = 0; j < wordSize; j++) {    // 对当前单词每一个位置修改
                    char c = s[j];  // 当前单词第 j 位字符
                    for (char k = 'a'; k <= 'z'; k++) {
                        if (c == k) continue;
                        s[j] = k;
                        if (WordList.count(s)) {    // 修改后合法
                            if (s == endWord) return step + 1;
                            if (!visited.count(s)) {
                                que.emplace(s);
                                visited.emplace(s);
                            }
                        }
                    }
                    s[j] = c;   // 当前单词当前位置修改回去
                }

            }
            step++;
        }
        return 0;
    }
};
// 字典数量 n  单词长度 m
// 嵌套三层循环，最外层 while 执行 n 次 ，第二层执行 m 次， 最内层执行 26 次
// 时间复杂度：O(n * m)

// 主要用了 set 存储字典; 空间复杂度：O(n)
// 有个疑问？ 第二层循环用了一个 char 变量。按道理来说应该是用了 n * m 个char。
// 这里空间复杂度是不是 O(n * m)呀？
