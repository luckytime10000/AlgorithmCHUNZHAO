学习笔记
使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方。
稍微修改一下二分查找的判定条件，代码如下：

int search(vector<int> data) {
int left = 0, right = data.size() - 1;
int end = right;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (data[mid] > data[mid + 1]) return mid;  // mid 与 mid + 1 之间是无序的
        if (data[mid] < data[end]) {    // mid 属于右侧有序部分，无序点在左侧
            right = mid - 1;
        } else {    // mid 属于左侧有序部分，无序点在右侧
            left = mid + 1;
        }
    }
    return 0;
}