// https://leetcode.com/problems/unique-number-of-occurrences/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
      unordered_map<int, int> freq;
      for (int x : arr) {
        freq[x]++;
      }
      vector<int> vis(arr.size()+1, 0);
      for (auto it : freq) {
        int cnt = it.second;
        if (vis[cnt]) {
          return false;
        }
        vis[cnt] = true;
      }
      return true;
    }
};
