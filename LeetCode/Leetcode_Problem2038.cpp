// https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/
class Solution {
public:
    bool winnerOfGame(string colors) {
        const int n = colors.size();
        map<char, int> cnt;
        
        int j = 0;
        for (int i = 1; i < n; i++) {
            char c = colors[i];
            char last = colors[j];
            if (c != last) {
                cnt[last] += max(i-j-2, 0);
                j = i;
            }
        }
        cnt[colors[j]] += max(n-j-2, 0);
        
        if (!cnt['A']) {
            return false;
        }
        
        return cnt['A'] > cnt['B'];
    }
};
