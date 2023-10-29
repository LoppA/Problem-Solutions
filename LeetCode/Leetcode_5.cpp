// https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
  
public:
    string longestPalindrome(string t) {
      string s;
      s += "#";
      for (auto c : t) {
        s += c;
        s += '#';
      }
      vector<int> p = vector<int>(s.size(), 0);

      int n = s.size();
      int c = 0, r = 0;
      for (int i = 0; i < n; i++) {
        int i_mirror = c - (i - c);

        if (i <= r)
          p[i] = min (p[i_mirror], r - i);
        else
          p[i] = 0;

        while (i - 1 - p[i] >= 0 and i + 1 + p[i] < n and s[i + 1 + p[i]] == s[i - 1 - p[i]]) {
          p[i]++;
        }

        if (i + p[i] > r) {
          c = i;
          r = i + p[i];
        }
      }

      int len = 0, center = 0;
      for (int i = 0; i < n; i++) 
        if (p[i] > len) {
          len = p[i];
          center = i;
        }

      string res;
      for (int i = 0; i < n; i++)
        if (i >= center - len and i <= center + len and s[i] != '#')
          res += s[i];
      
      return res;
    }
};
