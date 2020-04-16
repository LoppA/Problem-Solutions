class Solution {
public:
    bool checkValidString(string s) {
      int n = s.size();
      vector<bool> res(n+1, false);
      vector<bool> tmp(n+1);
      res[0] = true;
      
      for(int i = s.size()-1; i >= 0; i--) {
        fill(tmp.begin(), tmp.end(), false);
        
        for(int j = 0; j <= n; j++) {
          if(s[i] != '(' and j > 0 and res[j-1]) {
            tmp[j] = true;
          }
          if(s[i] != ')' and j+1 < n+1 and res[j+1]) {
            tmp[j] = true;
          }
          if(s[i] == '*' and res[j]) {
            tmp[j] = true;
          }
        }
        res = tmp;
      }
      
      return res[0];
    }
};
