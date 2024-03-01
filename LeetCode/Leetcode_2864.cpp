// https://leetcode.com/problems/maximum-odd-binary-number/
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
      int cnt[2] = {0, 0};
      
      for (char c : s) {
        cnt[c-'0']++;
      }
      
      string ret;
      ret.append(cnt[1]-1, '1');
      ret.append(cnt[0], '0');
      ret.append(1, '1');
      
      return ret;
    }
};
