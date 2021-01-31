class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        self.dfs(root, result)
        return result

    def dfs(self, root, res):
        if not root:
            return
        else:
            self.dfs(root.left, res)    # 递归左子树
            res.append(root.val)        # 处理当前结点
            self.dfs(root.right, res)   # 递归右子树
