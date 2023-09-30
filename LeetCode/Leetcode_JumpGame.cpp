class Solution {
public:
    bool canJump(vector<int>& nums) {
      const int n = nums.size();
      int i = 0, m = 0;
      while(i < n and i <= m) {
        m = max(m, i + nums[i]);
        i++;
      }
      return m >= n-1;
    }
};
