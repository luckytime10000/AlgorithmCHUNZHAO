import collections

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        # 手动维护一个最小堆，以[数字, 次数]中的次数作为比较的根据

        # 最小堆下沉函数
        # 输入 最小堆 当前的下标
        # 功能： 从当前下标开始下沉，直到最小堆合法
        def siftDown(minHeap, cur):
            val = minHeap[cur]      # 保存当前下标的值
            left = 2 * cur + 1
            right = 2 * cur + 2
            # mi 指向 左右儿子中较小者，最小堆需要较小值上位
            if right < len(minHeap) and minHeap[right][1] < minHeap[left][1]:
                mi = right
            else:
                mi = left
            # while 中只讨论右节点合法时的下沉
            while right < len(minHeap) and minHeap[mi][1] < val[1]:
                minHeap[cur] = minHeap[mi]      # 符合条件，下沉
                cur = mi    # 各个指针向下走
                left = 2 * cur + 1
                right = 2 * cur + 2
                if right < len(minHeap) and minHeap[right][1] < minHeap[left][1]:
                    mi = right
                else:
                    mi = left
            # 循环结束后： 没有右儿子 或者 值不符合条件

            # 如果有左儿子，直接与左儿子比较
            if left == len(minHeap) - 1 and minHeap[left][1] < val[1]:
                minHeap[cur] = minHeap[left]
                cur = left
            minHeap[cur] = val      # 把最开始的值放入正确位置

        # 最小堆上浮函数   上浮较小值
        # 输入 最小堆 当前下标
        # 功能：从当前下标开始上浮，直到最小堆合法
        def siftUp(minHeap, cur):
            val = minHeap[cur]  # 存储当前上浮的值
            par = (cur - 1) // 2    # 父节点下标
            while par >= 0 and val[1] < minHeap[par][1]:
                minHeap[cur] = minHeap[par]     # 符合条件，上浮
                cur = par
                par = (cur - 1) // 2
            minHeap[cur] = val      # 最开始的值放入正确位置

        stat = collections.Counter(nums)  # 返回字典 {"数字":出现次数}
        stat = list(stat.items())  # 返回嵌套列表 [[数字,出现次数], [], []]
        minHeap = []

        # 将前 k 个数字放入，构造最小堆
        for i in range(k):
            minHeap.append(stat[i])
            siftUp(minHeap, i)

        for i in range(k, len(stat)):
            if stat[i][1] > minHeap[0][1]:
                minHeap[0] = stat[i]
                siftDown(minHeap, 0)

        result = [row[0] for row in minHeap]
        return result
