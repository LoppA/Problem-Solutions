// https://leetcode.com/problems/binary-subarrays-with-sum/
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> cnt(nums.size()+1, 0);
        int sum = 0;
        int ans = 0;

        for (int x : nums) {
            cnt[sum]++;
            sum += x;
            int pre = sum-goal;
            if (pre >= 0)
                ans += cnt[pre];

        }

        return ans;
    }
};
