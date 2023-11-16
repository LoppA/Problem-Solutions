// https://leetcode.com/problems/find-unique-binary-string/
class Solution {
  
  int toInt(string str) {
    int val = 0;
    for (char c : str) {
      val <<= 1;
      val += c-'0';
    }
    return val;
  }
  
  string toString(int num, int n) {
    string str;
    for (int i = 0; i < n; i++) {
      str += num&1 ? '1' : '0';
      num >>= 1;
    }
    reverse(str.begin(), str.end());
    return str;
  }
  
public:
    string findDifferentBinaryString(vector<string>& nums) {
      int n = nums.size();
      vector<bool> vis(n+1, false);
      
      for (string num : nums) {
        int id = toInt(num);
        if (id <= n) {
          vis[id] = true;
        }
      }
      
      for (int i = 0; i < n; i++) {
        if (!vis[i]) {
          return toString(i, n);
        }
      }
      
      return toString(n, n);
    }
};
