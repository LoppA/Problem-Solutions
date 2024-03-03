// https://leetcode.com/problems/squares-of-a-sorted-array/
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
      int i = 0;
      int n = nums.size();
      while(i < n && nums[i] < 0) {
        i++;
      }
      if (i >= n) {
        i--;
      }
      
      auto sq = [](int x) -> int {
        return x*x;
      };
      
      if (i > 0 && sq(nums[i-1]) < sq(nums[i])) {
        i--;
      }
      
      int l = i-1, r = i+1;
      vector<int> v = {nums[i]*nums[i]};
      while(l >= 0 && r < n) {
        int L = sq(nums[l]);
        int R = sq(nums[r]);
        
        if (L < R) {
          v.push_back(L);
          l--;
        } else {
          v.push_back(R);
          r++;
        }
      }
      
      while(l >= 0) {
        v.push_back(sq(nums[l--]));
      }
      while(r < n) {
        v.push_back(sq(nums[r++]));
      }
      
      return v;
    }
};
