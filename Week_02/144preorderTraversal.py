class Solution(object):
    def preorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.preTra(root, result)
        return result

    def preTra(self, root, res):
        if root is None:
            return

        res.append(root.val)            # 处理当前结点
        self.preTra(root.left, res)     # 递归左子树
        self.preTra(root.right, res)    # 递归右子树
