// https://leetcode.com/problems/cherry-pickup-ii/
class Solution {
  const static int N = 71;
  int dp[N][N][N];
  
public:
    int cherryPickup(vector<vector<int>>& grid) {
      if (grid.empty()) {
        return 0;
      }
      int n = grid.size(), m = grid[0].size();
      
      memset(dp[n], 0, sizeof dp[n]);
      
      auto get = [this, &grid, n, m](int i, int j1, int j2) -> int {
        if (min(j1, j2) < 0 || max(j1, j2) >= m) {
          return 0;
        }

        int ret = dp[i][j1][j2];
        
        if (i >= n) {
          return ret;
        }

        ret += grid[i][j1];
        if (j1 != j2) {
          ret += grid[i][j2];
        }

        return ret;
      };
      
      auto calc = [this, &grid, &get](int i, int j1, int j2) -> void {
        int &val = dp[i][j1][j2];
        
        for (int l = -1; l <= 1; l++) {
          for (int r = -1; r <= 1; r++) {
            val = max(val, get(i+1, j1+l, j2+r));
          }
        }
      };
      
      for (int i = n-1; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
          for (int j2 = 0; j2 < m; j2++) {
            calc(i, j1, j2);
          }
        }
      }
      
      return get(0, 0, m-1);
    }
};
