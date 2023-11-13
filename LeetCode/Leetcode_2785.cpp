// https://leetcode.com/problems/sort-vowels-in-a-string/
class Solution {
  set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
  
  bool isVowel(char c) {
    return vowel.count(tolower(c));
  }
  
public:
    string sortVowels(string s) {
      vector<char> v;
      for (char c : s) {
        if (isVowel(c)) {
          v.push_back(c);
        }
      }
      sort(v.begin(), v.end());
      int i = 0;
      for (char &c : s) {
        if (isVowel(c)) {
          c = v[i++];
        }
      }
      return s;
    }
};
