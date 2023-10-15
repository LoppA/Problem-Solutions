// https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
class Solution {
    const static long long MOD = 1e9+7;
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps);
        vector<long long> dp(n+2, 0);
        dp[1] = 1;
        while(steps--) {
            vector<long long> tmp(n+2, 0);
            for (int i = 1; i <= n; i++) {
                tmp[i] = (dp[i-1]+dp[i]+dp[i+1]);
                while(tmp[i] >= MOD) {
                    tmp[i] -= MOD;
                }
            }
            dp = move(tmp);
        }
        return dp[1]%MOD;
    }
};
