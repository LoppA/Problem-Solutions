// https://leetcode.com/problems/minimum-common-value/
class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
      auto i = nums1.begin();
      auto j = nums2.begin();
      
      while(i != nums1.end() && j != nums2.end()) {
        if (*i == *j) {
          return *i;
        }
        if (*i < *j) {
          i++;
        } else {
          j++;
        }
      }
      
      return -1;
    }
};
