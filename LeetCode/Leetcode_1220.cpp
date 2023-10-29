// https://leetcode.com/problems/count-vowels-permutation/
class Solution {
  const int A = 0;
  const int E = 1;
  const int I = 2;
  const int O = 3;
  const int U = 4;
  const int MOD = 1e9+7;
  
public:
  int countVowelPermutation(int n) {
    vector<long long> dp(5, 1);
    
    for (int i = n-2; i >= 0; i--) {
      vector<long long> tmp(5);
      
      long long sum = accumulate(dp.begin(), dp.end(), 0L);
      sum %= MOD;
      
      tmp[A] = dp[E];
      tmp[E] = dp[A] + dp[I];
      tmp[I] = sum - dp[I];
      tmp[O] = dp[I] + dp[U];
      tmp[U] = dp[A];
        
      dp = move(tmp);
      for_each(dp.begin(), dp.end(), [this](long long &x) {
        x %= this->MOD;
        if (x < 0) {
          x += this->MOD;
        }
      }); 
    }
    
    return accumulate(dp.begin(), dp.end(), 0L)%MOD;
  }
};
