// https://leetcode.com/problems/parallel-courses-iii/
class Solution {
    typedef pair<int, int> ii;
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> g(n, vector<int>());
        vector<int> p(n, 0);
        for (const vector<int> &r : relations) {
            int u = r[0], v = r[1];
            u--;    v--;
            g[u].push_back(v);
            p[v]++;
        }
        priority_queue<ii, vector<ii>, greater<ii>> pq;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!p[i]) {
                pq.emplace(time[i], i);
                ans = max(ans, time[i]);
            }
        }
        
        while(pq.size()) {
            int t = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            for (int v : g[u]) {
                p[v]--;
                if (!p[v]) {
                    pq.emplace(t+time[v], v);
                    ans = max(ans, t+time[v]);
                }
            }
        }
        
        return ans;
    }
};
