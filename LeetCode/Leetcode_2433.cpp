// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
      vector<int> arr(pref.size());
      arr[0] = pref[0];
      for (int i = 1; i < (int)pref.size(); i++) {
        arr[i] = pref[i] ^ pref[i-1];
      }
      return arr;
    }
};

