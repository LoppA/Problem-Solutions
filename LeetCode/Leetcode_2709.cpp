// https://leetcode.com/problems/greatest-common-divisor-traversal/
class Solution {
  static const int N = 1e5+5;
  
  vector<int> g[N];
  int sieve[N], par[N];
  bool vis[N];
  
public:
    bool canTraverseAllPairs(vector<int>& nums) {
      if (nums.size() == 1) {
        return true;
      }
      
      for (int i = 2; i < N; i++) {
        if (!sieve[i]) {
          for (int j = i; j < N; j+=i) {
            sieve[j] = i;
          }
        }
      }
      
      for (int x : nums) {
        int num = x;
        if (num == 1) {
          return false;
        }
        while(num > 1) {
          int p = sieve[num];
          if (!par[p]) {
            par[p] = x;
          } else {
            int u = x, v = par[p];
            g[u].push_back(v);
            g[v].push_back(u);
          }
          
          while(num%p == 0) {
            num /= p;
          }
        }
      }
      
      queue<int> q;
      q.push(nums[0]);
      vis[nums[0]] = true;
      
      while(q.size()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
          if (!vis[v]) {
            vis[v] = true;
            q.push(v);
          }
        }
      }
      
      for (int x : nums) {
        if (!vis[x]) {
          return false;
        }
      }
      return true;
    }
};
