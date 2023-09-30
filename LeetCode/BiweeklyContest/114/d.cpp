// https://leetcode.com/contest/biweekly-contest-114/problems/maximum-number-of-k-divisible-components/
class Solution {
    static const int N = 3e4 + 4;
    vector<int> g[N];
    vector<int> v;
    int k;
    int ans;
    
    int go(int at, int pai) {
        int curr = v[at];
        
        for (int next : g[at]) {
            if (next == pai)    continue;
            curr += go(next, at)%k;
        }
        
        curr %= k;
        ans += !curr;
        
        return curr;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        for (auto e : edges) {
            int u = e[0], v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        this->v = values;
        this->k = k;
        
        ans = 0;
        go(0, -1);
        return ans;
    }
};

