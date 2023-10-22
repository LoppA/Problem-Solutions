// https://leetcode.com/problems/maximum-score-of-a-good-subarray/
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
      vector<int>::iterator l, r;
      l = r = nums.begin()+k;
      
      int curr = *l;
      int ans = curr;
      while(l != nums.begin() || r+1 != nums.end()) {
        if (l == nums.begin()) {
          r++;
          curr = min(curr, *r);
        } else if (r+1 == nums.end()) {
          l--;
          curr = min(curr, *l);
        } else {
          if (*(l-1) > *(r+1)) {
            l--;
            curr = min(curr, *l);
          } else {
            r++;
            curr = min(curr, *r);
          }
        }
        
        ans = max((long)ans, curr * (r-l+1));
      }
      
      return ans;
    }
};
