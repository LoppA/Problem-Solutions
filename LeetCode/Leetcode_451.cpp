// https://leetcode.com/problems/sort-characters-by-frequency/
class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char, int> freq;
      for (char c : s) {
        freq[c]++;
      }
      priority_queue<pair<int, char>> pq;
      for (auto it : freq) {
        pq.emplace(it.second, it.first);
      }
      string ret;
      while(!pq.empty()) {
        pair<int, char> p = pq.top();
        pq.pop();
        ret.insert(ret.end(), p.first, p.second);
      }
      return ret;
    }
};
