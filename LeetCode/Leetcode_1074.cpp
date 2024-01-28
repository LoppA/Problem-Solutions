// https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
class Solution {
  const int N = 100;
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
      if (matrix.empty()) {
        return 0;
      }
      int n = matrix.size(), m = matrix[0].size();
      
      auto getCell = [&matrix, n, m] (int i, int j) -> int {
        if (i < 0 || j < 0 || i >= n || j >= m) {
          return 0;
        }
        return matrix[i][j];
      };
      
      for (int i = 0; i < n; i++) {
        int row = 0;
        for (int j = 0; j < m; j++) {
          row += matrix[i][j];
          matrix[i][j] = row + getCell(i-1, j);
        }
      }
      
      int total = 0;
      for (int j2 = 0; j2 < m; j2++) {
        for (int j1 = 0; j1 <= j2; j1++) {
          unordered_map<int, int> freq;
          for (int i = 0; i < n; i++) {
            int val = target - getCell(i, j2) + getCell(i, j1-1);
            freq[val]++;
          }
          
          for (int i = 0; i < n; i++) {
            int _val = getCell(i-1, j1-1) - getCell(i-1, j2);
            total += freq[_val];
            
            int val = target - getCell(i, j2) + getCell(i, j1-1);
            freq[val]--;
          }
        }
      }
      
      return total;
    }
};
