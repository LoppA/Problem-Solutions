#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, m;

bool inside(ii p) {
	return p.first >= 0 && p.second >= 0 && p.first < n && p.second < m;
}

void process(map<char, vector<ii>> &mp, set<ii> &s, ii u, char c) {
	if (c == '.') {
		return;
	}

	auto add = [&s] (ii a, ii b) {
		ii x = {2 * a.first - b.first, 2 * a.second - b.second};

		if (inside(x)) {
			s.insert(x);
		}
	};

	for (auto v : mp[c]) {
		add(u, v);
		add(v, u);
	}

	if (!mp.count(c)) {
		mp[c] = vector<ii>();
	}
	mp[c].push_back(u);
}

int solve(vector<string> &g) {
	n = g.size();
	m = g[0].size();

	set<ii> s;
	map<char, vector<ii>> mp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			process(mp, s, {i, j}, g[i][j]);
		}
	}

	return s.size();
}

int main (void) {
	ios_base::sync_with_stdio(false);

	vector<string> g;
	string line;
	while (cin >> line) {
		g.push_back(line);
	}
	cout << solve(g) << endl;

	return 0;
}
