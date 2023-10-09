// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto range = equal_range(nums.begin(), nums.end(), target);
        if (range.first == nums.end()) {
            return {-1, -1};
        }
        int l = range.first-nums.begin();
        int r = range.second-nums.begin()-1;
        if (l > r) {
            return {-1, -1};
        }
        return {l, r};
    }
};
