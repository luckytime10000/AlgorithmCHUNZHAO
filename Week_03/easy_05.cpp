// 874. 模拟行走机器人
#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int result = 0, x = 0, y = 0;
    int direction = 0;  // 向北  方向 0 -> N, 1 -> E, 2 -> S, 3 -> W;
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> obstacles_set;
        for (int i = 0; i < obstacles.size(); i++) {    // 获取障碍物位置放入 set
            obstacles_set.emplace(make_pair(obstacles[i][0], obstacles[i][1]));
        }

        for (int i = 0; i < commands.size(); i++) { // 遍历指令，依次执行
            if (commands[i] > 0) {      // 行走
                move(obstacles_set, commands[i]);
                int tmp = x * x + y * y;
                result = tmp > result ? tmp : result;   // 更新最大值
            } else {    // 转向
                if (commands[i] == -1) direction = (direction + 1) % 4;
                else direction = (direction - 1 + 4) % 4;
            }
        }
        return result;
    }

    // n 个 指令， m 个 障碍物 依次遍历一遍; 时间复杂度：O(n+m)
    // 集合存放障碍物 + 4 个 int 变量; 空间复杂度：O(m)

    void move(set<pair<int, int>>& obstacles_set, int len) {
        switch (direction) {
            case 0:
                for (int i = 0; i < len; i++) {
                    if (obstacles_set.count({x, y + 1})) return;
                    y++;
                } break;
            case 1:
                for (int i = 0; i < len; i++) {
                    if (obstacles_set.count({x + 1, y})) return;
                    x++;
                } break;
            case 2:
                for (int i = 0; i < len; i++) {
                    if (obstacles_set.count({x, y - 1})) return;
                    y--;
                } break;
            case 3:
                for (int i = 0; i < len; i++) {
                    if (obstacles_set.count({x - 1, y})) return;
                    x--;
                } break;
        }
    }

};