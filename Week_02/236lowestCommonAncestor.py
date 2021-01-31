class Solution(object):
    def lowestCommonAncestor(self, root, p, q):
        """
        :type root: TreeNode
        :type p: TreeNode
        :type q: TreeNode
        :rtype: TreeNode
        """
        return self.dfs(root, p, q)

    def dfs(self, root, p, q):
        # 递归出口
        if not root:
            return None
        if root == p or root == q:
            return root

        x = self.dfs(root.left, p, q)       # 递归左子树
        y = self.dfs(root.right, p, q)      # 递归右子树

        if not x:
            return y  # p, q 不在左子树
        elif not y:
            return x  # p, q 在左子树，p, q 不在右子树
        else:
            return root  # p,q 在root的左右子树中
