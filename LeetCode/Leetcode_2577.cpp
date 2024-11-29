class Solution {
	typedef pair<int, int> ii;
	static const int INF = 1e9+9;
	int n;
	int m;

    bool inside(int i, int j) {
		if (i < 0 or j < 0 or i >= n or j >= m) {
			return false;
		}
		return true;
	}

public:
    int minimumTime(vector<vector<int>>& grid) {
		if (min(grid[0][1], grid[1][0]) > 1) {
			return -1;
		}
		n = grid.size();
		m = grid[0].size();
		priority_queue<pair<int,ii>, vector <pair<int,ii>>, greater<pair<int, ii>> > pq;
        pq.push({0, {0,0}});

		vector<vector<int>> vis(n, vector<int>(m, -1));
		vis[0][0] = 0;
        
        int dir[4][2] = {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0},
        };
        
        while(pq.size()) {
			int dist = pq.top().first;
			ii pos = pq.top().second;
            int i = pos.first;
            int j = pos.second;
			pq.pop();

			if (dist > vis[i][j]) {
				continue;
			}

			if (i == n-1 && j == m-1) {
				return dist;
			}

			for (int d = 0; d < 4; d++) {
				int ii = i + dir[d][0];
				int jj = j + dir[d][1];

				if (!inside(ii, jj)) {
					continue;
				}

				int x = max(vis[i][j]+1, grid[ii][jj]);
				if (x%2 != (ii+jj)%2) {
					x++;
				}
				if (vis[ii][jj] == -1) {
					vis[ii][jj] = x;
					pq.push({x, {ii, jj}});
				}
			}
        }

		return -1;
    }
};
