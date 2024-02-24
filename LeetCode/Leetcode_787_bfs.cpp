// https://leetcode.com/problems/cheapest-flights-within-k-stops/
class Solution {
  static const int N = 101;
  const int INF = 0x3f3f3f3f;
  
  typedef pair<int,int> ii;
  
  vector<ii> g[N];
  
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
      for (auto f : flights) {
        int u = f[0], v = f[1], cost = f[2];
        g[u].emplace_back(v, cost);
      }
      
      vector<int> dist(n, INF);
      dist[src] = 0;
      
      k++;
      while(k--) {
        vector<int> tmp = dist;
        
        for (int u = 0; u < n; u++) {
          for (auto edg : g[u]) {
            int v = edg.first;
            int cost = edg.second;
            tmp[v] = min(tmp[v], dist[u] + cost);
          }
        }
        
        dist = move(tmp);
      }
      
      return dist[dst] < INF ? dist[dst] : -1;
    }
};
