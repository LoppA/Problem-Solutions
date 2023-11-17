// https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
      int n = arr.size();
      int ans = n, at = n; 
      sort(arr.rbegin(), arr.rend());
      for (int x : arr) {
        if (at > x) {
          ans -= at - x;
          at = x;
        }
        at--;
      }
      return ans;
    }
};
