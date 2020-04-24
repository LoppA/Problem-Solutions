class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      long long x = 1;
      int diff = n-m;
      
      long long ans = 0;
      for(int i = 0; i < 32; i++) {
        if(diff <= x and (n&x) and (m&x)) {
          ans += x;
        }
        x <<= 1;
      }
      
      return ans;
    }
};
