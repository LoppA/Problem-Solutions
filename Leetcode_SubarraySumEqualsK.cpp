class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> cnt;
      int pre = 0;
      int ans = 0;
      for(int num : nums) {
        cnt[pre]++;
        pre += num;
        ans += cnt[pre-k];
      }
      return ans;
    }
};
