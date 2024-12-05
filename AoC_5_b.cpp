#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 100;
vector<int> g[N];

bool order(vector<int> &vec) {
	bool good = true;
	vector<int> pos(N, -1);

	for (int i = 0; i < (int)vec.size(); i++) {
		pos[vec[i]] = i;
	}

	int tt = 0;
	int i = 0;
	while(i < (int)vec.size()) {
		int u = vec[i];

		bool cont = false;
		for (int v : g[u]) {
			int j = pos[v];
			if (j > i) {
				swap(vec[i], vec[j]);
				pos[vec[i]] = i;
				pos[vec[j]] = j;
				cont = true;
				break;
			}
		}

		if (cont) {
			good = false;
			continue;
		}
		i++;
	}

	return good;
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
		g[v].push_back(u);
	}

	ll ans = 0;
	while (getline(cin, line)) {
		int i = 0;
		vector<int> v;
		while (i != (int)line.size()) {
			v.push_back(parse(line, i));
		}
		if (!order(v)) {
			ans += v[v.size()/2];
		}
	}

	cout << ans << endl;

	return 0;
}
