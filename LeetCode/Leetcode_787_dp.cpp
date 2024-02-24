// https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
  typedef pair<int, int> pi;
  
  static const int INF = 1e9;
    
  vector<vector<pi>> g;
  vector<vector<int>> dp;
  int dest;
  
  int go(int u, int step) {
    
    if (u == dest) {
      return 0;
    }
    
    if (step < 0) {
      return INF;
    }
    
    int &r = dp[u][step];
    if (r != -1) {
      return r;
    }
    
    r = INF;
    
    for (auto edg : g[u]) {
      int v = edg.first;
      int cost = edg.second;
      
      r = min(r, go(v, step-1) + cost);
    }
    
    return r;
  }
  
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    dest = dst;
    g = vector<vector<pi>>(n, vector<pi>());
    dp = vector<vector<int>>(n, vector(n+1, -1));
    
    for (auto flight : flights) {
      g[flight[0]].emplace_back(flight[1], flight[2]);
    }
    
    go(src, k);
    
    return dp[src][k] < INF ? dp[src][k] : -1;
  }
};
