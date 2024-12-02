class Solution {
    vector<string> split(string sentence) {
        vector<string> v;
        string s;
        
        for (char c : sentence) {
            if (c == ' ') {
                v.push_back(s);
                s = "";
            } else {
                s += c;
            }
        }
        
        v.push_back(s);
        return v;
    }
    
    bool pref(string s, string t) {
        if (s.size() < t.size()) {
            return false;
        }
        for (int i = 0; i < (int)t.size(); i++) {
            if (s[i] != t[i]) {
                return false;
            }
        }
        return true;
    }
    
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> words = split(sentence);
        
        for (int i = 0; i < (int)words.size(); i++) {
            if (pref(words[i], searchWord)) {
                return i+1;
            }
        }
        
        return -1;
    }
};
