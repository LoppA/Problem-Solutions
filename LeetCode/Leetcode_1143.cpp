// https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int n = text1.size(), m = text2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
      
      for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
          dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
          dp[i][j] = max(dp[i][j], dp[i+1][j+1] + (text1[i]==text2[j] ? 1 : 0));
        }
      }
      return dp[0][0];
    }
};
