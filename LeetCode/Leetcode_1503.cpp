// https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
      int t = 0;
      for (int x : left) {
        t = max(t, x);
      }
      for (int x : right) {
        t = max(t, n-x);
      }
      return t;
    }
};
