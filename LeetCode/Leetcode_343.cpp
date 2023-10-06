// https://leetcode.com/problems/integer-break/
class Solution {
public:
    int integerBreak(int n) {
        vector<vector<long long>> dp(2,
                vector<long long>(n+1, 0));
        
        dp[0][0] = 0;
        dp[0][1] = 1;
        for (int i = 1; i <= n; i++) {
            long long &a = dp[0][i], &b = dp[1][i];
            
            a = 0;
            b = i;
            
            for (int j = 1; j <= i; j++) {
                if (j < i) {
                    a = max(a, dp[1][i-j]*j);
                }
                b = max(b, dp[1][i-j]*j);
            }
        }
        return dp[0][n];
    }
};
