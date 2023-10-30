// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
      sort(arr.begin(), arr.end(), [](int a, int b) -> bool {
        int A = __builtin_popcount(a), B = __builtin_popcount(b);
        if (A != B) {
          return A<B;
        }
        return a<b;
      });
      return arr;
    }
};

