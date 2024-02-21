// https://leetcode.com/problems/bitwise-and-of-numbers-range/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
      int ans = 0;
      for (int i = 0, d = 1; i < 31; i++, d<<=1) {
        if (right-left <= d && (left&d) && (right&d)) {
          ans |= d;
        }
      }
      return ans;
    }
};
