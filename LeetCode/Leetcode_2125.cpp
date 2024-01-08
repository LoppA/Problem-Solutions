// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
      int prev = 0;
      int beams = 0;
      
      for (const string &s : bank) {
        int cnt = 0;
        for (char c : s) {
          cnt += c=='1';
        }
        if (!cnt) {
          continue;
        }
        
        beams += prev * cnt;
        prev = move(cnt);
      }
      
      return beams;
    }
};
