// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-operations-to-collect-elements/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        reverse(nums.begin(), nums.end());
        vector<bool> vis(k+1, false);
        int cnt = k;
        int ans = 0;
        for (int x : nums) {
            ans++;
            if (x > k) continue;
            cnt -= !vis[x];
            vis[x] = true;
            if (!cnt) {
                return ans;
            }
        }
        return -1;
    }
};

