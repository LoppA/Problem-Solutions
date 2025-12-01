#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, m;
vector<string> g;

int go(int I, int J) {
	queue<ii> q;
	set<ii> vis;

	q.emplace(I, J);
	vis.emplace(I, J);

	int dir[4][2] = {
		{1,0},
		{-1,0},
		{0,1},
		{0,-1},
	};

	auto inside = [] (int i, int j) -> bool {
		auto check = [](int i, int n) -> bool {
			return 0 <= i && i < n;
		};
		return check(i, n) && check(j, m);
	};

	int ans = 0;
	while(q.size()) {
		int i = q.front().first;
		int j = q.front().second;
		q.pop();

		ans += (g[i][j] == '9');

		for (int d = 0; d < 4; d++) {
			int ii = i + dir[d][0];
			int jj = j + dir[d][1];

			if (inside(ii, jj)
					&& !vis.count({ii, jj})
					&& g[ii][jj] == g[i][j] + 1) {
				q.emplace(ii, jj);
				vis.emplace(ii, jj);
			}
		}
	}

	return ans;
}

ll go() {
	n = g.size();
	m = g[0].size();

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += g[i][j] == '0' ? go(i, j) : 0;
		}
	}

	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string line;
	while(getline(cin, line)) {
		g.push_back(line);
	}
	cout << go() << endl;

	return 0;
}
