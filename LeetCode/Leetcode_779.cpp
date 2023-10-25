// https://leetcode.com/problems/k-th-symbol-in-grammar/
class Solution {
public:
    int kthGrammar(int n, int k) {
      bool curr = 0;
      int m = (1<<(n-1));
      while(n != 1) {
        m >>= 1;
        if (k > m) {
          curr = !curr;
          k -= m;
        }
        n--;
      }
      return curr;
    }
};
