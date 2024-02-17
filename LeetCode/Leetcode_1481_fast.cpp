// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      if (k >= arr.size()) {
        return 0;
      }
      unordered_map<int, int> freq;
      for (int num : arr) {
        freq[num]++;
      }
      vector<int> v;
      for (auto it : freq) {
        v.push_back(it.second);
      }
      sort(v.rbegin(), v.rend());
      
      int total = (int)arr.size() - k;
      for (int i = 0; i < v.size(); i++) {
        total -= v[i];
        if (total <= 0) {
          return i+1;
        }
      }
      
      return 0;
    }
};
