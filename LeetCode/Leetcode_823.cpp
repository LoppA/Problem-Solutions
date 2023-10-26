// https://leetcode.com/problems/binary-trees-with-factors/
class Solution {
  typedef pair<int, int> ii;
  static const int MOD = 1e9+7;
  
public:
  int numFactoredBinaryTrees(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    set<int> s;
    map<int, vector<ii>> m;
    for (int x : arr) {
      s.insert(x);
      for (int a : arr) {
        if (x%a == 0 and s.count(x/a)) {
          if (!m.count(x)) {
            m[x] = vector<ii>();
          }
          m[x].emplace_back(a, x/a);
        }
      }
    }
    
    long long ans = 0;
    map<int, long long> dp;
    for (int x : arr) {
      dp[x] = 1;
      for (const ii &p : m[x]) {
        dp[x] += dp[p.first]*dp[p.second];
        dp[x] %= MOD;
      }
      ans += dp[x];
    }
    
    ans %= MOD;
    return ans;
  }
};
