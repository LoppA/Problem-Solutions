// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> freq;
        
        int l = 0, r = 0;
        int dup = 0, ans = n;
        while(l < n) {
            while(r < n && nums[r] < nums[l]+n) {
                if(freq[nums[r]] > 0) {
                    dup++;
                }
                freq[nums[r]]++;
                r++;
            }
            
            ans = min(ans, n - (r-l) + dup);
            
            int num = nums[l];
            dup -= freq[num]-1;
            while(l < n && nums[l] == num) {
                l++;
            }
        }
        
        return ans;
    }
};
