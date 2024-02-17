// https://leetcode.com/problems/rearrange-array-elements-by-sign/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      queue<int> q[2];

      for (int num : nums) {
        q[num <= 0].push(num);
      }

      int n = nums.size();

      vector<int> res;
      while(n) {
        res.push_back(q[0].front());
        q[0].pop();
        res.push_back(q[1].front());
        q[1].pop();
        n-=2;
      }

      return res;
    }
};
