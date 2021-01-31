class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """

        def dfs(n, k, begin, path, res):
            # 递归出口 若满 k 个数，则结果中添加当前路径
            if len(path) == k:
                res.append(list(path))
                return
            # 1 -> n  对每一个数深度优先遍历所有的可能性
            for i in range(begin, n + 1):
                path.append(i)
                dfs(n, k, i + 1, path, res)  # 不满足k个数，递归，保证后面的数比前面大  避免重复
                path.pop()  # 回溯

        result = []
        path = []
        dfs(n, k, 1, path, result)
        return result
