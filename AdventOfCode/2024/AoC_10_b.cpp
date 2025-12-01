#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, m;
vector<string> g;


int dir[4][2] = {
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
};
map<ii, ll> dp;

inline bool check (int i, int n) {
	return 0 <= i && i < n;
};

inline bool inside (int i, int j)  {
	return check(i, n) && check(j, m);
};

ll go(int i, int j) {
	if (g[i][j] == '9') {
		return 1;
	}

	ii pij = make_pair(i, j);
	if (dp.count(pij)) {
		return dp[pij];
	}

	ll &r = dp[pij];

	if (r) {
		return r;
	}

	for (int d = 0; d < 4; d++) {
		int ii = i + dir[d][0];
		int jj = j + dir[d][1];

		if (inside(ii, jj) && g[ii][jj] == g[i][j] + 1) {
			r += go(ii, jj);
		}
	}

	return r;
}

ll go() {
	n = g.size();
	m = g[0].size();

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dp.clear();

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
