// https://leetcode.com/problems/find-players-with-zero-or-one-losses/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      map<int, int> freq;
      for (const vector<int> &match : matches) {
        int w = match[0], l = match[1];
        auto include = [&freq](int player) -> void {
          if (!freq.count(player)) {
            freq[player] = 0;
          }
        };
        include(w);
        include(l);
        freq[l]++;
      }
      
      vector<vector<int>> winners(2, vector<int>());
      for (auto it : freq) {
        if (it.second > 1) {
          continue;
        }
        winners[it.second].push_back(it.first);
      }
      
      return winners;
    }
};
