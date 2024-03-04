// https://leetcode.com/problems/bag-of-tokens/
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
      sort(tokens.begin(), tokens.end());
      int n = tokens.size();
      int l = 0, r = n-1;
      int score = 0, maxScore = 0;
      while(l <= r) {
        if (power >= tokens[l]) {
          power -= tokens[l++];
          score++;
        } else {
          if (score) {
            score--;
            power += tokens[r--];
          } else {
            break;
          }
        }
        maxScore = max(score, maxScore);
      }
      
      return maxScore;
    }
};
