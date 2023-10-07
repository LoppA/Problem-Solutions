// https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
class Solution {
    typedef long long ll;
    static const int N = 51, M = 103;
    
    const ll mod = 1e9+7;
    ll dp[N][M][N], acc[N][M];
    
public:
    int numOfArrays(int n, int m, int k) {
        memset(dp, 0, sizeof dp);
        for (int j = 0; j < M; j++) {
            dp[n][j][0] = 1;
        }
        
        
        for (int i = n-1; i >= 0; i--) {
            memset(acc, 0, sizeof acc);
            for (int cost = 0; cost <= k; cost++) {
                for (int prev = m; prev >= 0; prev--) {
                    acc[cost][prev] = acc[cost][prev+1] + dp[i+1][prev][cost];
                    if (acc[cost][prev] >= mod) acc[cost][prev] -= mod;
                }
            }
            
            for (int cost = 0; cost <= k; cost++) {
                for (int prev = 0; prev <= m; prev++) {
                    ll &r = dp[i][prev][cost];
                    
                    r = dp[i+1][prev][cost] * prev;
                    r %= mod;
                    
                    if (!cost)  continue;
                    
                    r += acc[cost-1][prev+1];
                    if (r > mod)    r -= mod;
                }
            }
        }
        
        return dp[0][0][k];
    }
};

