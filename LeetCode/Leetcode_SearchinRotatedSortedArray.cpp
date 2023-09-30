class Solution {
  int findPivot(vector<int>& nums) {
    if(!nums.size())  return -1;
    int bot = 0, top = nums.size()-1;
    int ret = nums.size()-1;
    
    while(bot <= top) {
      int mid = (bot+top)>>1;
      if(nums[mid] < nums[0]) {
        ret = mid-1;
        top = mid-1;
      } else {
        bot = mid + 1;
      }
    }
    return ret;
  }
  int bSearch(vector<int>& nums, int bot, int top, int target) {
    while(bot <= top) {
      int mid = (bot+top)>>1;
      if(nums[mid] == target) {
        return mid;
      } else if(nums[mid] < target) {
        bot = mid+1;
      } else {
        top = mid-1;
      }
    }
    return -1;
  }
public:
    int search(vector<int>& nums, int target) {
      int m = findPivot(nums);
      
      int first = bSearch(nums, 0, m, target);
      if(first != -1) {
        return first;
      }
      return bSearch(nums, m+1, nums.size()-1, target);
    }
};
