#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int go(const vector<string> &g) {
	const int n = g.size(), m = g[0].size();
	int dir[4][2] = {
		{-1,0},
		{0,1},
		{1,0},
		{0,-1},
	};

	int d = 0;

	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m && g[i][j] != '^'; j++) {}
		if (g[i][j] == '^') {
			break;
		}
	}

	auto inside = [&n, &m] (int i, int j) -> bool {
		return i >= 0 && j >= 0 && i < n && j < m;
	};

	int ans = 0;
	vector<vector<int>> vis(n, vector<int>(m, 0));
	while(inside(i, j)) {
		if (!vis[i][j]) {
			ans++;
		}
		vis[i][j] |= (1<<d);

		int ii = i + dir[d][0];
		int jj = j + dir[d][1];

		if (!inside(ii, jj)) {
			return ans;
		}

		if (g[ii][jj] != '#') {
			i = ii;
			j = jj;
		} else {
			d = (d+1)%4;
		}
	}


	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	vector<string> g;
	string line;
	while(getline(cin, line)) {
		g.push_back(line);
	}
	cout << go(g) << endl;

	return 0;
}
