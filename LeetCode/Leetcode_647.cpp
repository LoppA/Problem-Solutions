// https://leetcode.com/problems/palindromic-substrings/
class Solution {
  
  int manacher(string t) {
    string s = "#";
    for (char c : t) {
      s += c;
      s += '#';
    }
    
    int n = s.size();
    vector<int> p(n);
    int c = 0, r = 0;
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
      int i_mirror = c - (i-c);
      if (i <= r) {
        p[i] = min(p[i_mirror], r-i);
      } else {
        p[i] = 0;
      }
      
      while (i - 1 - p[i] >= 0 and i + 1 + p[i] < n and s[i + 1 + p[i]] == s[i - 1 - p[i]]) {
			  p[i]++;
		  }
      
      ans += (p[i]+1)/2;

      if (i + p[i] > r) {
        c = i;
        r = i + p[i];
      }
    }
      
    return ans;
  }
public:
    int countSubstrings(string s) {
      return manacher(s);
    }
};
