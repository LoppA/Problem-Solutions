// https://leetcode.com/problems/determine-if-string-halves-are-alike/
class Solution {
  const set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  
  bool isVowel(char c) {
    c = tolower(c);
    return vowels.count(c);
  }
  
public:
    bool halvesAreAlike(string s) {
      int L = 0, R = 0;
      int m = s.size()/2;
      int i = 0;
      for (char c : s) {
        if (i < s.size()/2) {
          L += isVowel(c);
        } else {
          R += isVowel(c);
        }
        
        i++;
      }
      
      return L == R;
    }
};
