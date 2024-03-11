// https://leetcode.com/problems/custom-sort-string/
class Solution {
public:
    string customSortString(string order, string s) {
      unordered_map<char, int> pos;
      for (int i = 0; i < (int)order.size(); i++) {
        pos[order[i]] = i;
      }
      
      sort(s.begin(), s.end(), [&pos] (char a, char b) -> bool {
        return pos[a] < pos[b];
      });
      
      return s;
    }
};
