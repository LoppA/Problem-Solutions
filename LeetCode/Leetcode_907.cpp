// https://leetcode.com/problems/sum-of-subarray-minimums/
class Solution {
  static const int mod = 1e9 + 7;
  typedef pair<int, int> ii;
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      vector<int> l(n), r(n);
      
      stack<ii> s;
      for (int i = 0; i < n; i++) {
        while(!s.empty() && s.top().first > arr[i]) {
          s.pop();
        }
        l[i] = s.empty() ? 0 : s.top().second + 1;
        s.emplace(arr[i], i);
      }
      s = stack<ii>();
      for (int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top().first >= arr[i]) {
          s.pop();
        }
        r[i] = s.empty() ? n-1 : s.top().second - 1;
        s.emplace(arr[i], i);
      }
      
      long long ans = 0;
      for (int i = 0; i < n; i++) {
        long long cnt = (r[i]-i+1)*(i-l[i]+1);
        ans += cnt * arr[i];
      }
      
      return ans%mod;
    }
};
