class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        # 先判空，保证调用 dfs 时不放入 None
        if root is None:
            return []
        result = []
        self.por(root, result)
        return result

    def por(self, root, res):
        # 先遍历子节点  再添加当前结点值
        for ele in root.children:
            self.por(ele, res)
        res.append(root.val)
