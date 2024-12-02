#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main (void) {
	ios_base::sync_with_stdio(false);

	int a, b;
	vector<ll> l;
	map<ll, int> cnt;
	while (cin >> a >> b) {
		l.push_back(a);
		cnt[b]++;
	}

	ll ans = 0;
	for (auto x : l) {
		ans += x * cnt[x];
	}

	cout << ans << endl;

	return 0;
}
