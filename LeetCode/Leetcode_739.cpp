// https://leetcode.com/problems/daily-temperatures/
class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<int> s;
    vector<int> ans(n, 0);
    for (int i = n-1; i >= 0; i--) {
      int t = temperatures[i];
      
      while(!s.empty() && t >= temperatures[s.top()]) {
        s.pop();
      }
      
      ans[i] = s.empty() ? 0 : s.top()-i;
      
      s.emplace(i);
    }
    
    return ans;
  }
};
