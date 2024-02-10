// https://leetcode.com/problems/largest-divisible-subset/
class Solution {
  const static int N = 1e3 + 3;
  vector<int> g[N];
  int dp[N];
  
  int go(int i) {
    int &r = dp[i];
    
    if (r != -1) {
      return r;
    }
    
    r = 0;
    for (int j : g[i]) {
      r = max(r, go(j));
    }
    
    r += 1;
    return r;
  }
  
  vector<int> ret;
  void trace(int i) {
    ret.push_back(i);
    
    for (int j : g[i]) {
      if (dp[i] == dp[j] + 1) {
        trace(j);
        return;
      }
    }
  }
    
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      
      for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
          if (nums[j]%nums[i] == 0) {
            g[i].push_back(j);
          }
        }
      }
      
      memset(dp, -1, sizeof dp);
      int len = 0, beg = 0;
      for (int i = 0; i < n; i++) {
        int l = go(i);
        if (l > len) {
          len = l;
          beg = i;
        }
      }
      
      trace(beg);
      for (int &i : ret) {
        i = nums[i];
      }
      return ret;
    }
};
