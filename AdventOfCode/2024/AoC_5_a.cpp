#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 100;
vector<int> g[N];

bool ordered(vector<int> &vec) {
	vector<bool> vis(N, false);

	for (int u : vec) {
		for (int v : g[u]) {
			if (vis[v]) {
				return false;
			}
		}

		vis[u] = true;
	}

	return true;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	auto parse = [](string& s, int &i) -> int {
		int val = 0;
		while(i < (int)s.size()) {
			char c = s[i++];
			if (c >= '0' && c <= '9') {
				val = val*10 + c-'0';
			} else {
				return val;
			}
		}
		assert(0 < val && val < N);
		return val;
	};

	string line;
	while (getline(cin, line) && !line.empty()) {
		int i = 0;
		int u = parse(line, i);
		int v = parse(line, i);
		g[u].push_back(v);
	}

	ll ans = 0;
	while (getline(cin, line)) {
		int i = 0;
		vector<int> v;
		while (i != (int)line.size()) {
			v.push_back(parse(line, i));
		}
		if (ordered(v)) {
			ans += v[v.size()/2];
		}
	}

	cout << ans << endl;

	return 0;
}
