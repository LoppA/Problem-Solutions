// https://leetcode.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
      long long dp[2] = {1, 0};
      while(--n >= 0) {
        long long tmp = dp[0] + dp[1];
        dp[1] = dp[0];
        dp[0] = tmp;
      }
      return dp[0];
    }
};
