class Solution(object):
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        result = [0, 1]
        two = 1
        three = 1
        five = 1

        for i in range(2, n + 1):
            # 所有丑数都是由丑数×2 3 5 得到的
            # 从 1 开始，对丑数 × 2 3 5 得到最小值 就是下一个丑数
            m = min(min(result[two] * 2, result[three] * 3), result[five] * 5)
            result.append(m)
            # 如果当前添加的丑数 == 上某个丑数 × 2 3 5 得到  则那一个丑数指向下一个丑数
            if m == result[two] * 2:
                two += 1
            if m == result[three] * 3:
                three += 1
            if m == result[five] * 5:
                five += 1

        return result[n]
