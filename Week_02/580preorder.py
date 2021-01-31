class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        # 先判空，保证调用 dfs 时不放入 None
        if not root:
            return []
        result = []
        self.dfs(root, result)
        return result

    def dfs(self, root, res):
        # 添加当前结点值 再遍历子节点
        res.append(root.val)
        for ele in root.children:
            self.dfs(ele, res)
