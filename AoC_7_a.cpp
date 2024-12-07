#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll parse(const string& s, int& i) {
	ll val = 0;
	bool f = false;

	while(i < (int)s.size()) {
		char c = s[i++];
		if (c >= '0' && c <= '9') {
			f = true;
			val = val*10 + c-'0';
			assert(val > 0);
		} else if (f) {
			return val;
		}
	}

	return val;
}

bool search(vector<ll>& v, ll curr, int i, ll T) {
	if (curr > T) {
		return false;
	}
	if (i == (int)v.size()) {
		return T == curr;
	}

	if (search(v, curr + v[i], i+1, T)) {
		return true;
	}

	return search(v, curr * v[i], i+1, T);
}

ll go(const string& line) {
	int i = 0;
	ll T = parse(line, i);

	vector<ll> v;
	while(i < (int)line.size()) {
		v.push_back(parse(line, i));
	}

	if (search(v, v[0], 1, T)) {
		return T;
	}
	return 0;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string line;
	ll ans = 0;
	while(getline(cin, line)) {
		ans += go(line);
	}
	cout << ans << endl;

	return 0;
}
lo
