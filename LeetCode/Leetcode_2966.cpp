// https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
      int n = nums.size();
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      
      for (int i = 0; i < n; i += 3) {
        ans.push_back(vector<int>());
        for (int j = 0; j < 3; j++) {
          ans.back().push_back(nums[i+j]);
        }
        
        if (ans.back().back() - ans.back().front() > k) {
          return {};
        }
      }
      
      return ans;
    }
};
