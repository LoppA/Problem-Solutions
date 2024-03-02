// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int, int> id;
      for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        int y = target - x;
        
        if (id.count(y)) {
          return {i, id[y]};
        }
        
        id[x] = i;
      }
      
      return {};
    }
};
