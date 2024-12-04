#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const string TARGET = "XMAS";

char get(vector<string> &g, int i, int j) {
	if (i < 0 || j < 0 || i >= (int)g.size() || j >= (int)g[i].size()) {
		return '#';
	}
	return g[i][j];
}

bool check(vector<string> &g, int i, int j, int di, int dj) {
	for (int k = 0; k < (int)TARGET.size(); k++, i+=di, j+=dj) {
		if (get(g, i, j) != TARGET[k]) {
			return false;
		}
	}
	return true;
}

int go(vector<string> &g, int di, int dj) {
	int n = g.size(), m = g[0].size();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += check(g, i, j, di, dj);
		}
	}

	return ans;
}

int go(vector<string> &g) {
	int ans = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			ans += go(g, i, j);
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
