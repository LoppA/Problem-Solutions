// https://leetcode.com/problems/painting-the-walls/
class Solution {
  const static int N = 501;
  long long dp[N][N];
  vector<int> time, cost;
  int n;
  
  long long go(int i, int j) {
    if (j >= n) {
      return 0;
    }
    if (i >= n) {
      return 1e9;
    }
    long long &r = dp[i][j];
    if (r != -1) {
      return r;
    }
    


    
    return r =
      min(go(i+1,j),
      go(i+1,j+time[i]+1)+cost[i]);
  }
  
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
      n = cost.size();
      this->cost = cost;
      this->time = time;
      memset(dp, -1, sizeof dp);
      return go(0,0);

    }
};
