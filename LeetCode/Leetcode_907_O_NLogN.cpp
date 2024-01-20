// https://leetcode.com/problems/sum-of-subarray-minimums
class Solution {
  static const int mod = 1e9 + 7;
  typedef pair<int, int> ii;
public:
    int sumSubarrayMins(vector<int>& arr) {
      int n = arr.size();
      priority_queue<ii, vector<ii>, greater<ii>> pq;
      for (int i = 0; i < n; i++) {
        pq.emplace(arr[i], i);
      }
      
      set<int> s;
      
      long long ans = 0;
      while(pq.size()) {
        int val = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        
        auto it = s.insert(i).first;
        long long l = 0, r = n-1;
        if (it != s.begin()) {
          l = *prev(it)+1;
        }
        if (next(it) != s.end()) {
          r = *next(it)-1;
        }
        
        long long cnt = (i-l+1)*(r-i+1);
        ans += cnt * val;
      }
      
      return ans%mod;
    }
};
