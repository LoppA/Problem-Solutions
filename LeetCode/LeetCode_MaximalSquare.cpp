class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      if(!matrix.size())  return 0;
      const int n = matrix.size(), m = matrix[0].size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
      
      int maxSide = 0;
      for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
          if(matrix[i-1][j-1] == '0') {
            dp[i][j] = 0;
          } else {
            const int side = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            dp[i][j] = side + 1;
            maxSide = max(maxSide, dp[i][j]);
          }
        }
      }
      
      return maxSide * maxSide;
    }
};
