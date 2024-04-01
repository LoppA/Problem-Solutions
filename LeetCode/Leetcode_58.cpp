// https://leetcode.com/problems/length-of-last-word/
class Solution {
public:
    int lengthOfLastWord(string s) {
      int n = s.size();
      int i = n-1;
      
      while(i >= 0 && s[i] ==  ' ') {
        i--;
      }
      n = i;
      
      while(i >= 0 && s[i] != ' ') {
        i--;
      }
      
      return n-i;
    }
};
