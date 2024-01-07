// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
class Solution {
  static const int N = 1e3 + 3;
  map<long long, long long> dp[N];
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
      int n = nums.size();
      
      long long ans = 0;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
          long long d = (long long)nums[i] - (long long)nums[j];
          dp[i][d]++;
          if (dp[j][d]) {
            dp[i][d] += dp[j][d];
            ans += dp[j][d];
          }
        }
      }
      
      return ans;
    }
};
