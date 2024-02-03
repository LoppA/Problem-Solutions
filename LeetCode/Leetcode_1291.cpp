// https://leetcode.com/problems/sequential-digits/
class Solution {
  int low, high;
  vector<int> v;
  
  void go(int i, int d) {
    if (i > high) {
      return;
    }
    
    if (i >= low) {
      v.push_back(i);
    }
    
    if (d == 9) {
      return;
    }
    
    go(i*10+d+1, d+1);
  }
  
public:
  vector<int> sequentialDigits(int low, int high) {
    this->low = low;
    this->high = high;
    for (int i = 1; i <= 9; i++) {
      go(i, i);
    }
    sort(v.begin(), v.end());
    return v;
  }
};
