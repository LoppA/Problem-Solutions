// https://leetcode.com/problems/find-the-winner-of-an-array-game/
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
      int n = arr.size();
      int curr = 0;
      int i = 0, j = 1;
      while(j < n) {
        if (arr[i] > arr[j]) {
          curr++;
          j++;
        } else {
          curr = 1;
          i = j;
          j = i+1;
        }
        if (curr >= k) {
          return arr[i];
        }
      }
      
      return *max_element(arr.begin(), arr.end());
    }
};
