// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
class Solution {
  map<char, int> buildFreq(string s) {
    map<char, int> freq;
    for (char c : s) {
      freq[c]++;
    }
    return freq;
  }
public:
    int minSteps(string s, string t) {
      map<char, int> freqS = buildFreq(s), freqT = buildFreq(t);
      
      int ans = 0;
      for (auto it : freqS) {
        int l = it.second;
        int r = freqT[it.first];
        if (l > r) {
          ans += l-r;
        }
      }
      return ans;
    }
};
