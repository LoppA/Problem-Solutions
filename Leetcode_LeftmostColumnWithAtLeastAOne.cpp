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
      
      int bot = 0, top = m-1;
      int ans = -1;
      while(bot <= top) {
        int mid = (bot+top)>>1;
        
        bool f = false;
        for(int i = 0; i < n; i++) {
          f |= binaryMatrix.get(i, mid) == 1;
        }
        
        if(f) {
          ans = mid;
          top = mid-1;
        } else {
          bot = mid+1;
        }
      }
      
      return ans;
    }
};
