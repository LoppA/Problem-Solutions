#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

map<pair<ll, int>, ll> dp;

inline int dig(ll x) {
	int d = 0;
	while(x) {
		x /= 10;
		d++;
	}
	return d;
}

ll go(ll x, int y = 25) {
	assert(x >= 0);
	int d = dig(x);
	if (y == 0) {
		return 1;
	}

	pair<ll, int> p(x, y);
	if (dp.count(p)) {
		return dp[p];
	}

	if (x == 0) {
		return dp[p] = go(1, y-1);
	}
	if (d%2 == 0) {
		d /= 2;
		ll l = x, r = 0;
		ll base = 1;

		while(d--) {
			r += base*(l%10);
			base *= 10
			l /= 10;
		}
		return dp[p] = go(l, y-1) + go(r, y-1);
	}

	return dp[p] = go(x*2024, y-1);
}

int main (void) {
	ios_base::sync_with_stdio(false);


	ll x;
	ll ans = 0;
	while(cin >> x) {
		ans += go(x);
	}
	cout << ans << endl;

	return 0;
}
