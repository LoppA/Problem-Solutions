// https://leetcode.com/problems/majority-element/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
      if (nums.empty()) {
        return -1;
      }
      int n = nums.size();
      int res = nums[0], freq = 0;
      for (int num : nums) {
        freq += (res == num) ? 1 : -1;
        
        if (!freq) {
          res = num;
          freq = 1;
        }
      }
      
      return res;
    }
};
