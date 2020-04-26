class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int **dp, n = text1.size(), m = text2.size();
      dp = new int*[n+1];
      for(int i = 0; i <= n; i++) {
        dp[i] = new int[m+1];
      }
      
      for(int i = 0; i <= m; i++) {
        dp[n][i] = 0;
      }
      
      for(int i = n-1; i >= 0; i--) {
        dp[i][m] = 0;
        for(int j = m-1; j >= 0; j--) {
          int &cur = dp[i][j];
          cur = 0;
          if(text1[i] == text2[j]) {
            cur = dp[i+1][j+1] + 1;
          }
          
          cur = max(cur, max(dp[i+1][j], dp[i][j+1]));
        }
      }
      
      int ans = dp[0][0];
      for(int i = 0; i <= n; i++) {
        delete[] dp[i];
      }
      delete[] dp;
      
      return ans;
    }
};
