// https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
      if (nums.size() < 3) {
        return -1;
      }
      sort(nums.begin(), nums.end());
      
      long long pref = accumulate(nums.begin(), nums.end(), 0L);
      int i = nums.size();
      while(i > 2) {
        i--;
        long long high = nums[i];
        pref -= high;
        
        if (high < pref) {
          return high + pref;
        }
      }
      
      return -1;
    }
};
