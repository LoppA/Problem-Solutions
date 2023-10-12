// https://leetcode.com/problems/find-in-mountain-array/
/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int findPeak(MountainArray &arr, int n) {
        int bot = 1, top = n-1;
        
        int i = 0;
        while(bot <= top) {
            int mid = (bot+top)>>1;
            
            if (arr.get(mid-1) < arr.get(mid)) {
                i = mid;
                bot = mid+1;
            } else {
                top = mid-1;
            }
        }
        
        return i;
    }
    
    int find(MountainArray &arr, int bot, int top, int target, function<bool(int, int)> cmp) {
        while(bot <= top) {
            int mid = (bot+top)>>1;
            int value = arr.get(mid);
            if (value == target) {
                return mid;
            }
            if (cmp(value, target)) {
                bot = mid+1;
            } else {
                top = mid-1;
            }
            
        }
        return -1;
    }
    
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int j = findPeak(mountainArr, n);
        
        int l = find(mountainArr, 0, j, target,
                     [](int a, int b) -> bool {
                         return a<b;
                     });
        int r = find(mountainArr, j+1, n-1, target,
                     [](int a, int b) -> bool {
                         return a>b;
                     });
        
        return l == -1 ? r : l;
    }
};
