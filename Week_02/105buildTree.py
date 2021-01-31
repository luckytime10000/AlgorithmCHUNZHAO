class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        size = len(preorder)
        return self.build(preorder, 0, size, inorder, 0, size)

    # 参数分别为：前序序列，前序左边界，前序有边界，中序序列，中序左边界，中序有边界 (序列边包含界均)
    def build(self, pre, pleft, pright, ino, ileft, iright):
        # 递归出口
        if pleft > pright or ileft > iright or pleft == len(pre):
            return None
        if pleft == pright:
            return TreeNode(pre[pleft])

        result = TreeNode(pre[pleft])  # 以前序的左边界的值 创建当前的根结点
        num = ileft
        while pre[pleft] != ino[num]:
            num += 1    # 让 num 指向中序序列中 当前根结点的值
        num -= ileft    # 左子树包含结点的个数
        result.left = self.build(pre, pleft + 1, pleft + num, ino, ileft, ileft + num - 1)      # 递归创建左子树
        result.right = self.build(pre, pleft + num + 1, pright, ino, ileft + num + 1, iright)   # 递归创建右子树

        return result
