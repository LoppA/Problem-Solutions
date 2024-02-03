// https://leetcode.com/problems/partition-array-for-maximum-sum/
class Solution {
public:
  int maxSumAfterPartitioning(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n+1, 0);
    for (int i = n-1; i >= 0; i--) {
      int val = arr[i];
      for (int j = 0; j < k && i+j < n; j++) {
        val = max(val, arr[i+j]);
        dp[i] = max(dp[i], dp[i+j+1] + val*(j+1));
      }
    }
    return dp[0];
  }
};
