// https://leetcode.com/contest/biweekly-contest-114/problems/minimum-number-of-operations-to-make-array-empty/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> freq;
        for (int x : nums) {
            freq[x]++;
        }
        int ans = 0;
        for (auto it : freq) {
            int y = it.second;
            if (y == 1) {
                return -1;
            }
            ans += (y+2)/3;
        }
        return ans;
    }
};
