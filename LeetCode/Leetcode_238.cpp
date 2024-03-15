// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> suf(n+1);
      suf.back() = 1;
      for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i+1]*nums[i];
      }
      
      vector<int> ans(n);
      int pref = 1;
      for (int i = 0; i < n; i++) {
        ans[i] = pref * suf[i+1];
        pref *= nums[i];
      }
      return ans;
    }
};
