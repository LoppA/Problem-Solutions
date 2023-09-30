// https://leetcode.com/contest/biweekly-contest-114/problems/split-array-into-maximum-number-of-subarrays/
class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int t = nums[0];
        for (int x : nums) {
            t &= x;
        }
        if (t) {
            return 1;
        }
        
        int ans = 0;
        int at = nums[0];
        for (int i = 0; i < (int)nums.size(); i++) {
            at &= nums[i];
            if (!at) {
                ans++;
                if (i == (int)nums.size() - 1) {
                    return ans;
                }
                at = nums[i+1];
            }
        }
        return ans;
    }
};

