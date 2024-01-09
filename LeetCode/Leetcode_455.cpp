// https://leetcode.com/problems/assign-cookies/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      priority_queue<int> greeds(g.begin(), g.end()), sizes(s.begin(), s.end());
      
      int total = 0;
      while(greeds.size() && sizes.size()) {
        if (sizes.top() >= greeds.top()) {
          total++;
          sizes.pop();
          greeds.pop();
        } else {
          greeds.pop();
        }
      }
      return total;
    }
};
