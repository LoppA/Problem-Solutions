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

void add(set<ii> &s, ii u, ii v) {
	int dx = u.first - v.first;
	int dy = u.second - v.second;

	if (dy == 0) {
		dx = 1;
	} else if (dx == 0) {
		dy = 1;
	} else {
		int g = gcd(dx, dy);
		dx /= g;
		dy /= g;
	}

	auto nav = [&s, &u](int dx, int dy) -> void{
		int x = u.first;
		int y = u.second;

		while(inside({x, y})) {
			s.emplace(x, y);
			x += dx;
			y += dy;
		}
	};

	nav(dx, dy);
	nav(-dx, -dy);
}

void process(map<char, vector<ii>> &mp, set<ii> &s, ii u, char c) {
	if (c == '.') {
		return;
	}

	for (auto v : mp[c]) {
		add(s, u, v);
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
