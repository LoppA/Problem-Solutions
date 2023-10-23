// https://leetcode.com/problems/power-of-four/
class Solution {
public:
    bool isPowerOfFour(int n) {
      if (n <= 0)  return false;
      while(n != 1) {
        if (n&3) {
          return false;
        }
        n >>= 2;
      }
      return true;
    }
};

