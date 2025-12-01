#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int get(vector<string> &g, int i, int j) {
	if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[i].size()) {
		return 0;
	}
	return g[i][j] == 'M' ? 1 : (g[i][j] == 'S' ? 2 : 0);
}

int go(vector<string> &g) {
	int n = (int)g.size(), m = (int)g[0].size();
	int ans = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			auto check = [&g, &i, &j] (int di, int dj) -> bool {
				int a = get(g, i+di, j+dj);
				int b = get(g, i-di, j-dj);
				return a && b && a != b;
			};

			if (g[i][j] == 'A') {
				bool L = check(1, 1);
				bool R = check(1, -1);
				ans += L && R;
			}
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
