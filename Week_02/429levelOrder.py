from collections import deque

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: Node
        :rtype: List[List[int]]
        """
        if not root:
            return None
        result = []
        que = deque()
        que.append(root)    # 根结点入队

        while que:
            size = len(que)     # 记录每一层的结点数量
            tmp = []            # 存放该层所有结点
            for i in range(size):   # 遍历该层结点
                x = que.popleft()       # 该层结点出队
                tmp.append(x.val)       # 放入临时变量 tmp 中
                for ele in x.children:  # 将该结点所有子节点入队
                    que.append(ele)
            result.append(tmp)   # 遍历完该层，将该层的所有结点放入结果列表

        return result
