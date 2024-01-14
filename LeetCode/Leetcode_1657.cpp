// https://leetcode.com/problems/determine-if-two-strings-are-close/
class Solution {
  class Normalized {
    map<char, int> freq;
    vector<int> sortedFreq;
  
  public:
    Normalized(string word) {
      for(char c : word) {
        freq[c]++;
      }
      for (auto it : freq) {
        sortedFreq.push_back(it.second);
      }
      sort(sortedFreq.begin(), sortedFreq.end());
    }
    
    bool operator == (const Normalized &other) const {
      if (freq.size() != other.freq.size() ||
          sortedFreq != other.sortedFreq) {
        return false;
      }
      
      auto i = freq.begin(), j = other.freq.begin();
      while(i != freq.end()) {
        if (i->first != j->first) {
          return false;
        }
        i++;
        j++;
      }
      return true;
    }
  };

  vector<int> getFreq(string word) {
    map<char, int> freq;
    for (char c : word) {
      freq[c]++;
    }
    vector<int> v;
    for (auto it : freq) {
      v.push_back(it.second);
    }
    sort(v.begin(), v.end());
    return v;
  }

public:
    bool closeStrings(string word1, string word2) {
      return Normalized(word1) == Normalized(word2);
    }
};
