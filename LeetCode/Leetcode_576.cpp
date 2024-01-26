// https://leetcode.com/problems/out-of-boundary-paths/
class Solution {
  const static int N = 51;
  const static int MOD = 1e9+7;
  int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
  int n, m;
  vector<vector<vector<int>>> dp;
  
  bool outside(int i, int j) {
    return i < 0 || j < 0 || i >= n || j >= m;
  }
  
  int dfs(int i, int j, int moves) {
    if (outside(i, j)) {
      return 1;
    }
    if (!moves) {
      return 0;
    }
    
    int &ret = dp[i][j][moves];
    if (ret != -1) {
      return ret;
    }
    
    ret = 0;
    
    for (int d = 0; d < 4; d++) {
      ret += dfs(i+dir[d][0], j+dir[d][1], moves-1);
      if (ret > MOD) {
        ret -= MOD;
      }
    }
    
    return ret;
  }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
      this->n = m;
      this->m = n;
      dp = vector<vector<vector<int>>>(this->n,
        vector<vector<int>>(this->m,
          vector<int>(maxMove+1, -1)));
      return dfs(startRow, startColumn, maxMove);
    }
};
