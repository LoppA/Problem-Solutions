// https://leetcode.com/problems/backspace-string-compare/
class Solution {
    string process(const string &s) {
        string r;
        for (char c : s) {
            if (c == '#') {
                if (!r.empty()) {
                    r.pop_back();
                }
            } else {
                r += c;
            }
        }
            
        return r;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
