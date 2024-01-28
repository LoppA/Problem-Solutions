// https://leetcode.com/problems/k-inverse-pairs-array/
class Solution {
  static const int mod = 1e9+7;
public:
  int kInversePairs(int n, int k) {
    vector<int> dp = {1};
    for (int i = 1; i <= n; i++) {
      vector<int> tmp;
      int l = 0-i+1, r = 0;
      long long val = 0;
      while(l < static_cast<int>(dp.size()) && tmp.size() <= k) {
        if (r < dp.size()) {
          val += dp[r];
          if (val >= mod) {
            val -= mod;
          }
        }
        r++;
        tmp.push_back(val);
        if (l >= 0) {
          val -= dp[l];
          if (val <= 0) {
            val += mod;
          }
        }
        l++;
      }
      dp = move(tmp);
    }
    
    return k >= dp.size() ? 0 : dp[k];
  }
};
