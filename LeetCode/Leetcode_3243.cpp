class Solution {

	int bfs(vector<int> &steps, vector<vector<int>> &adj, int a, int b) {

		queue<int> q;
		q.push(a);

		while(q.size()) {
			int u = q.front();
			q.pop();

			for (int v : adj[u]) {
				if (steps[u]+1 < steps[v]) {
					steps[v] = steps[u]+1;
					q.push(v);
				}
			}
		}

		return steps[b];
	}

public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
		vector<int> steps(n);
		vector<vector<int>> adj(n, vector<int>());
		for (int i = 0; i < n; i++) {
			steps[i] = i;
			if (i) {
				adj[i-1].push_back(i);
			}
		}

		vector<int> ans;
		for (auto &edg : queries) {
			int u = edg[0];	int v = edg[1];
			adj[u].push_back(v);
			ans.push_back(bfs(steps, adj, u, n-1));
		}

		return ans;
	}
};
