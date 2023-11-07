// https://leetcode.com/problems/eliminate-maximum-number-of-monsters/
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
      int n = dist.size();
      vector<int> freq(n+1, 0);
      for (int i = 0; i < n; i++) {
        int t = (dist[i]+speed[i]-1) / speed[i];
        if (t <= n) {
          freq[t]++;
        }
      }
      
      int shots = 0;
      int ans = 0;
      for (int t = 0; t <= n; t++) {
        if (freq[t] > shots) {
          ans += shots;
          return ans;
        }
        
        ans += freq[t];
        shots -= freq[t];
        shots++;
      }
      
      return n;
    }
};
