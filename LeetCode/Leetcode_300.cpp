// https://leetcode.com/problems/longest-increasing-subsequence/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> v;
      
      for (int x : nums) {
        auto it = lower_bound(v.begin(), v.end(), x);
        if (it == v.end()) {
          v.push_back(x);
        } else {
          *it = x;
        }
      }
      
      return v.size();
    }
};
