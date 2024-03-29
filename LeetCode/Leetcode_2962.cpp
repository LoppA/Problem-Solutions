// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
      int n = nums.size();
      int val = *max_element(nums.begin(), nums.end());
      
      int l = 0, r = 0, cnt = 0;
      long long ans = 0;
      while(l < n) {
        while(r < n && cnt < k) {
          cnt += (nums[r++] == val);
        }
        
        if (cnt == k) {
          ans += n-r+1;
        }
        
        cnt -= (nums[l++] == val);
      }
      return ans;
    }
};
