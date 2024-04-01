// https://leetcode.com/problems/subarray-product-less-than-k/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      if (k <= 1) return 0;
      int n = nums.size();
      int l = 0, r = 0;
      int ans = 0;

      int m = 1;
      while(l < n) {
        while(m < k && r < n) {
          m *= nums[r++];
        }
        ans += m < k ? r-l : r-l-1;
        m /= nums[l];
        l++;
      }

      return ans;
    }
};

