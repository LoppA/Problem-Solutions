/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
      vector<int> dim = binaryMatrix.dimensions();
      int n = dim[0], m = dim[1];
      int ans = m;
      
      for(int i = 0; i < n; i++) {
        while(ans > 0 and binaryMatrix.get(i, ans-1) == 1) {
          ans--;
        }
      }
      
      return (ans == m ? -1 : ans);
    }
};
