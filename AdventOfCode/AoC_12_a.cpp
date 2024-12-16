#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<vector<bool>> vis;
vector<string> g;
int n, m;
ll a, p;

int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
};

inline char get(int i, int j) {
	if (i < 0 || j < 0 || i >=n || j >= m) {
		return '#';
	}
	return g[i][j];
}

void go(int i, int j) {
	a++;
	vis[i][j] = true;

	for (int d = 0; d < 4; d++) {
		int ii = i + dir[d][0];
		int jj = j + dir[d][1];

		if (get(ii, jj) != g[i][j]) {
			p++;
		} else if (!vis[ii][jj]) {
			go(ii, jj);
		}
	}
}

ll go() {
	n = g.size();
	m = g[0].size();
	vis = vector<vector<bool>>(n, vector<bool>(m, false));

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a = 0;
			p = 0;
			if (!vis[i][j]) {
				go(i, j);
				ans += a*p;
			}
		}
	}
	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string line;
	while(cin >> line) {
		g.push_back(line);
	}
	cout << go() << endl;

	return 0;
}
