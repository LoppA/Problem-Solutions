// https://leetcode.com/problems/maximum-profit-in-job-scheduling/
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
      int n = startTime.size();
      vector<tuple<int,int,int>> v;
      for (int i = 0; i < n; i++) {
        v.emplace_back(startTime[i], endTime[i], profit[i]);
      }
      sort(v.begin(), v.end());
      
      vector<int> dp(n+1, 0);
      auto it = v.end();
      for (int i = n-1; i >= 0; i--) {
        int l, r, p;
        tie(l, r, p) = v[i];
        
        int j = lower_bound(it, v.end(), make_tuple(r, 0, 0)) - v.begin();
        it--;
        
        dp[i] = max(dp[i+1], p + dp[j]);
      }
      
      return dp[0];
    }
};
