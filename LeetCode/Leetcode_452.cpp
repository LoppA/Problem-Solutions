// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      sort(points.begin(), points.end(), [](vector<int>& a, vector<int> &b) -> bool {
        return a[0] < b[0];
      });
      
      const int n = points.size();
      int ans = 0, i = 0;
      while(i < n) {
        ans++;
        int r = points[i][1];
        while(i < n && points[i][0] <= r) {
          i++;
          r = min(i < n ? points[i][1] : r, r);
        }
      }
      
      return ans;
    }
};
