// https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
      unordered_map<int, int> freq;
      for (int num : arr) {
        freq[num]++;
      }
      sort(arr.begin(), arr.end(), [&freq](int a, int b) {
        int fa = freq[a], fb = freq[b];
        if (fa == fb) {
          return a < b;
        }
        return fa < fb;
      });
      
      int uniq = freq.size();
      for (int i = 0; i < k; i++) {
        freq[arr[i]]--;
        if (!freq[arr[i]]) {
          uniq--;
        }
      }
      
      return uniq;
    }
};
