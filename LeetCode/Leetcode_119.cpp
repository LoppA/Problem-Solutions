// https://leetcode.com/problems/pascals-triangle-ii/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> v = {0, 1, 0};
        while(rowIndex--) {
            vector<int> tmp = move(v);
            v = vector<int>(tmp.size()+1);
            int n = v.size();
            for (int i = 1; i < n-1; i++) {
                v[i] = 1;
                v[i] = tmp[i-1]+tmp[i];
            }
        }
        v.erase(v.begin());
        v.pop_back();
        return v;
    }
};
