// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
class Solution {
public:
    int minimumLength(string s) {
      int l = 0, r = s.size()-1;
      
      while(r != l && s[l] == s[r]) {
        char c = s[l];
        
        while(r-l >= 0 && s[l] == c) {
          l++;
        }
        
        while(r-l >= 0 && s[r] == c) {
          r--;
        }
      }
      
      return r-l+1;
    }
};
