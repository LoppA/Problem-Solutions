// https://leetcode.com/problems/first-unique-character-in-a-string/
class Solution {
public:
    int firstUniqChar(string s) {
      vector<int> freq(300, 0);
      for (char c : s) {
        freq[c]++;
      }
      for (int i = 0; i < (int)s.size(); i++) {
        if(freq[s[i]] == 1) {
          return i;
        }
      }
      return -1;
    }
};
