// https://leetcode.com/problems/build-an-array-with-stack-operations/
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
      vector<string> ans;
      int curr = 1;
      
      for (int x : target) {
        while (curr < x) {
          ans.push_back("Push");
          ans.push_back("Pop");
          curr++;
        }
        ans.push_back("Push");
        curr++;
      }
      
      return ans;
    }
};
