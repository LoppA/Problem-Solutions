// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
      const int n = nums.size();
      int ans = 0;
      int l = 0, r = 0;
      map<int, int> freq;
      while(l < n) {
        while(r < n) {
          if (freq[nums[r]]+1 > k) {
            break;
          }
          freq[nums[r]]++;
          r++;
        }
        ans = max(ans, r-l);
        freq[nums[l]]--;
        l++;
      }
      
      return ans;
    }
};
