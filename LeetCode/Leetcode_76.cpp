// https://leetcode.com/problems/minimum-window-substring/
class Solution {
public:
    string minWindow(string s, string t) {
      int n = s.size();
      
      int cnt = 0;
      // unordered_map<char, int> m;
      vector<int> m(300, 0);
      for (char c : t) {
        if (!m[c]) {
          cnt++;
        }
        m[c]++;
      }
        
      int L = -1, R = n+1; 
      int l = 0, r = 0;
      while(l < n) {
        while(r < n && cnt) {
          char c = s[r];
          m[c]--;
          if (!m[c]) {
            cnt--;
          }
          r++;
        }
        
        if (cnt) {
          break;
        }
        
        if (r-l < R-L) {
          R = r;
          L = l;
        }
        
        char c = s[l];
        if (!m[c]) {
          cnt++;
        }
        m[c]++;
        
        l++;
      }
      
      return L == -1 ? "" : s.substr(L, R-L);
    }
};
