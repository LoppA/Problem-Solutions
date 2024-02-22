// https://leetcode.com/problems/find-the-town-judge/
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      vector<int> out(n+1, 0), in(n+1, 0);
      for (auto edg : trust) {
        int u = edg[0], v = edg[1];
        out[u]++;
        in[v]++;
      }
      
      int judge = -1;
      for (int i = 1; i <= n; i++) {
        if (out[i] == 0 && in[i] == n-1) {
          if (judge != -1) {
            return -1;
          }
          judge = i;
        }
      }
      return judge;
    }
};
