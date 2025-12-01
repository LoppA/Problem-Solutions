#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll process(const string &s) {
	vector<int> v;

	int id = 0;
	int i = 0;
	while(i < (int)s.size()) {
		auto parse = [](char c) -> int {
			return c-'0';
		};
		int m = parse(s[i++]);
		v.insert(v.end(), m, id++);

		if (i == (int)s.size()) {
			break;
		}

		m = parse(s[i++]);
		v.insert(v.end(), m, -1);
	}

	int n = v.size();
	int l = 0, r = n - 1;

	while(l < r) {
		while(l < n && v[l] != -1) {
			l++;
		}

		while(r >= 0 && v[r] == -1) {
			r--;	
		}

		if (l < r) {
			swap(v[l++], v[r--]);
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		ans += v[i] == -1 ? 0LL : i*v[i];
	}
	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	cout << process(s) << endl;

	return 0;
}
