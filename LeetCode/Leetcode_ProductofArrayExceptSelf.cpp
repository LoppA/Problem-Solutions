class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      const int n = nums.size();
      vector<int> output(n, 1);
      
      int pref = 1;
      for(int i = 0; i < n; i++) {
        output[i] *= pref;
        pref *= nums[i];
      }
      
      int suff = 1;
      for(int i = n-1; i >= 0; i--) {
        output[i] *= suff;
        suff *= nums[i];;
      }
      
      return output;
    }
};
