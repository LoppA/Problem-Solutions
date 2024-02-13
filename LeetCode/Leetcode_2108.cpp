// https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
class Solution {
  
  bool isPalindrome(const string &word) {
    int i = 0, j = word.size()-1;
    
    while(i < j) {
      if (word[i++] != word[j--]) {
        return false;
      }
    }
    
    return true;
  }
  
public:
    string firstPalindrome(vector<string>& words) {
      for (string word : words) {
        if (isPalindrome(word)) {
          return word;
        }
      }
        
      return "";
    }
};
