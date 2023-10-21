// https://leetcode.com/problems/constrained-subsequence-sum/
class Solution {
  int k, t;
  deque<pair<int, int>> d;
  
  void add(int x) {
    while (!d.empty() and t-d.front().second >= k) {
      d.pop_front();
    }
    
    while(!d.empty() and d.back().first <= x) {
      d.pop_back();
    }
    
    if (x < 0) {
      t++;
      return;
    }
    
    d.emplace_back(x, t++);
  }
  
  
  int getMax() {
    if (d.empty()) {
      return 0;
    }
    return d.front().first;
  }
  
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      this->k = k;
      this->t = 0;
      
      int n = nums.size();
      for (int i = n-1; i >= 0; i--) {
        nums[i] += getMax();
        add(nums[i]);
      }
      
      return *max_element(nums.begin(), nums.end());
    }
};

