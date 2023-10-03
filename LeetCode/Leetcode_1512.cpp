class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        long long goodPairs = 0;
        unordered_map<int, int> freq;
        for (int num : nums) {
            goodPairs += freq[num]++;
        }
        return goodPairs;
    }
};
