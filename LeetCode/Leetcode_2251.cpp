// https://leetcode.com/problems/number-of-flowers-in-full-bloom/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, vector<int>> ev, id;
        for (const vector<int> &flower : flowers) {
            ev[flower[0]].push_back(1);
            ev[flower[1]+1].push_back(-1);
        }
        for (int i = 0; i < (int)people.size(); i++) {
            ev[people[i]].push_back(0);
            id[people[i]].push_back(i);
        }
        
        int sum = 0;
        for (const auto &it : ev) {
            int t = it.first;
            const vector<int> &v = it.second;
            for (auto x : v) {
                if (x) {
                    sum += x;
                }
            }
            
            if (!id.count(t)) {
                continue;
            }
            
            for (int i : id[t]) {
                people[i] = sum;
            }
        }
        
        return people;
    }
};
