// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
      vector<vector<int>> m;
      map<int, int> freq;
      
      for (int num : nums) {
        if (freq[num] >= m.size()) {
          m.push_back({});
        }
        
        m[freq[num]].push_back(num);
        freq[num]++;
      }
      
      return m;
    }
};
