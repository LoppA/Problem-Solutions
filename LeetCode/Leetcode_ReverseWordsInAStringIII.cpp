// https://leetcode.com/problems/reverse-words-in-a-string-iii/submissions/
class Solution {
public:
    string reverseWords(string s) {
        int j = 0;
        int n = s.size();
        for (int i = 1; i < n; i++) {
            if (s[i] == ' ') {
                reverse(s.begin()+j, s.begin()+i);
                j = i+1;
            }
        }
        reverse(s.begin()+j, s.begin()+n);
        return s;
    }
};
