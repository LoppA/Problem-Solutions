// https://leetcode.com/problems/group-anagrams/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
      unordered_map<string, vector<string>> m;
      for (string str : strs) {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        if (!m.count(sorted)) {
          m[sorted] = vector<string>();
        }
        m[sorted].push_back(str);
      }
      
      vector<vector<string>> ret;
      for (auto it : m) {
        ret.push_back(move(it.second));
      }
      return ret;
    }
};
