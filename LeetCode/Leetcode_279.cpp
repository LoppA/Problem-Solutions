// https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    int numSquares(int n) {
      vector<int> nums;
      for (int i = 1; i*i <= n; i++) {
        nums.push_back(i*i);
      }
      
      vector<int> dp(n+1, 0);
      dp[0] = 0;
      for (int i = 1; i <= n; i++) {
        dp[i] = dp[i-1]+1;
        for (int j = 0; j < (int)nums.size() && nums[j] <= i; j++) {
          dp[i] = min(dp[i], dp[i-nums[j]]+1);
        }
      }
      return dp[n];
    }
};
