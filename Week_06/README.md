63. 不同路径 II
状态转移方程：
  二维dp数组：
    if (obstacleGrid[i][j] == 1) dp[i][j] = 0;
    if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

  一维dp数组：
    if (obstacleGrid[i][j] == 1) dp[j] = 0;
    if (obstacleGrid[i][j] == 0) dp[j] += dp[j - 1];
    
