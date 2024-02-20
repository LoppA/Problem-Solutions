// https://leetcode.com/problems/missing-number/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      
      int flag = (1<<20);
      
      for (int i = 0; i < n; i++) {
        int j = nums[i] & (flag-1);
        if (j == n) {
          continue;
        }
        
        nums[j] |= (1<<20);
      }
      
      for (int i = 0; i < n; i++) {
        if (!(nums[i]>>20)) {
          return i;
        }
      }
      
      return n;
    }
};
