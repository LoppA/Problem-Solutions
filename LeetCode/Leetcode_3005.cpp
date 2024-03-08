// https://leetcode.com/problems/count-elements-with-maximum-frequency/
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
      unordered_map<int, int> freq;
      for (int x : nums) {
        freq[x]++;
      }
      int f = 0, ans = 0;
      for (auto it : freq) {
        int _f = it.second;
        if (_f == f) {
          ans++;
        } else if (_f > f) {
          ans = 1;
          f = _f; 
        }
      }
      
      return f * ans;
    }
};
