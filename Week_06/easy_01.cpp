// 1122. 数组的相对排序

#include <vector>
#include <algorithm>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> m2;
        for (auto& ele: arr2) m2[ele] = 0;  // 初始化map

        vector<int> result(arr1.size());
        int index = 0;  // 存放未出现在 arr2 的元素的下标

        for (auto& ele: arr1) {
            if (m2.count(ele)) m2[ele]++;
            else result[index++] = ele;
        }

        vector<int> tmp(index);     // 未出现在 arr2 的元素
        for (int i = 0; i < index; i++) tmp[i] = result[i];
        sort(tmp.begin(), tmp.end());

        int k = 0;  // 依次放入结果集
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < m2[arr2[i]]; j++) {
                result[k++] = arr2[i];
            }
        }
        for (int i = 0; i < index; i++) result[k++] = tmp[i];

        return result;
    }
};

// 时间复杂度：O(m + n)     两个数组的长度
// 空间复杂度：O(m + n)

