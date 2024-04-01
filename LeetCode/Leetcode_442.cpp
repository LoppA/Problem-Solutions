// https://leetcode.com/problems/find-all-duplicates-in-an-array/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      const int B = 20;
      const int mask = (1<<B)-1;
      for(int x : nums) {
        x = x&mask;
        int f = nums[x-1]>>B;
        f++;
        nums[x-1] = (nums[x-1]&mask) | f<<B;
      }

      int i = 0;
      for (int x = 1; x <= (int)nums.size(); x++) {
        int f = nums[x-1]>>B;
        if (f == 2) {
          nums[i++] = x;
        }
      }

      nums.resize(i);
      return nums;
    }
};
