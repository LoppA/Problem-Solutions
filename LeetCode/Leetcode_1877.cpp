// https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
class Solution {
public:
    int minPairSum(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int n = nums.size();
      int ans = nums[0] + nums.back();
      for (int i = 0; i < n/2; i++) {
        ans = max(nums[i]+nums[n-1-i], ans);
      }
      return ans;
    }
};
