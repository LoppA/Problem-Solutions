// https://leetcode.com/problems/intersection-of-two-arrays/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());
      
      auto i = nums1.begin(), j = nums2.begin();
      
      auto walk = [](const vector<int> &v, vector<int>::iterator &i, int val) -> void {
        while(i != v.end() && *i == val) {
          i++;
        }
      };
      
      vector<int> inter;
      while(i != nums1.end() && j != nums2.end()) {
        if (*i == *j) {
          int tmp = *i;
          inter.push_back(tmp);
          walk(nums1, i, tmp);
          walk(nums2, j, tmp);
        } else if (*i < *j) {
          i++;
        } else { // *i > *j
          j++;
        }
      }
      
      return inter;
    }
};
