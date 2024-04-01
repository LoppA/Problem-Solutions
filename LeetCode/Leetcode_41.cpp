// https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int n = nums.size();
      nums.push_back(0);
      
      auto inRange = [&n] (int i) -> bool {
        return 1 <= i && i <= n;
      };
      
      for (int i = 0; i < n; i++) {
        while(inRange(nums[i]) && nums[nums[i]] != nums[i]) {
          swap(nums[i], nums[nums[i]]);
        }
      }
      
      for (int i = 1; i <= n; i++) {
        if (nums[i] != i) {
          return i;
        }
      }
      
      return n+1;
    }
};
