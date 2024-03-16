// https://leetcode.com/problems/contiguous-array/
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        m[0] = n;
        int sum = 0;
      
        transform(nums.begin(), nums.end(), nums.begin(),
                 [](int x) {
                   return x ? 1 : -1;
                 });
      
        for(int i = n-1; i >= 0; i--) {
            sum += nums[i];
            if (!m[sum]) {
                m[sum] = i;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, m[sum]-i);
            sum -= nums[i];
        }
        
        return ans;
    }
};
