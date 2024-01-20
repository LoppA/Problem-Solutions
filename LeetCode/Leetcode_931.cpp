// https://leetcode.com/problems/minimum-falling-path-sum/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
      int n = matrix.size();
      vector<vector<int>> dp(n+1, vector<int>(n, 0));
          
      auto getCell = [&dp, n](int i, int j) -> int {
        if (j < 0 || j >= n) {
          return INT_MAX;
        }
        return dp[i][j];
      };
      
      for (int i = n-1; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
          dp[i][j] = matrix[i][j] +
            min(getCell(i+1, j),
                min(getCell(i+1, j-1), getCell(i+1, j+1)));
        }
      }
      
      return *min_element(dp[0].begin(), dp[0].end());
    }
};
