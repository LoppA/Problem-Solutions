class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;

    unordered_map<int, int> m;
    int pre = 0;
    m[0] = -1;

    for(int i = 0; i < n; i++) {
      pre = pre + (nums[i] ? 1 : -1);

      if(m.count(pre)) {
        ans = max(ans, i-m[pre]);
      }

      if(!m.count(pre)) {
        m[pre] = i;
      }
    }

    return ans;
  }
};
