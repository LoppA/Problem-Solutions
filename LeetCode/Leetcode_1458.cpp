// https://leetcode.com/problems/max-dot-product-of-two-subsequences/
class Solution {
    typedef pair<int, int> ii;
    
    pair<int, int> add(const pair<int, int> &p, int val) {
        return ii(p.first + val, p.second + 1);
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<ii>>dp(n+1, vector<ii>(m+1, ii(0,0)));
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                ii &r = dp[i][j];
                
                r = add(dp[i+1][j+1], nums1[i]*nums2[j]);
                
                r = max(r, dp[i][j+1]);
                r = max(r, dp[i+1][j]);
            }
        }
        
        if (!dp[0][0].second) {
            sort(nums1.begin(), nums1.end());
            sort(nums2.begin(), nums2.end());
            if (nums1.front() < nums2.front()) {
                swap(nums1, nums2);
            }
            return nums1.front()*nums2.back();
        }
        
        return dp[0][0].first;
    }
};

