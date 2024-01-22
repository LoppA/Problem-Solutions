// https://leetcode.com/problems/set-mismatch/
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      int n = nums.size();
      vector<int> cnt(n+1, 0);
      
      vector<int> ans;
      for (int num : nums) {
        cnt[num]++;
        if (cnt[num] == 2) {
          ans.push_back(num);
        }
      }
      
      for (int i = 1; i <= n; i++) {
        if (!cnt[i]) {
          ans.push_back(i);
        }
      }
      
      return ans;
    }
};
