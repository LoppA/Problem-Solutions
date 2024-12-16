#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef __int128 LL;
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

namespace i_want_to_use_y1 {

ll x1, y1;
ll x2, y2;
ll X, Y;

bool read() {
	string line;
	int i;

	auto parse = [&line, &i] () -> ll {
		ll val = 0;
		while(i < (int)line.size()) {
			char c = line[i++];
			if (c >= '0' && c <= '9') {
				val = val*10 + c-'0';
			} else if (val) {
				return val;
			}
		}
		return val;
	};

	if(!getline(cin, line)) {
		return false;
	}
	i = 0;
	x1 = parse();
	y1 = parse();

	getline(cin, line);
	i = 0;
	x2 = parse();
	y2 = parse();

	getline(cin, line);
	i = 0;
	X = parse() + 10000000000000LL;
	Y = parse() + 10000000000000LL;

	getline(cin, line);
	return true;
}

ll go() {
	ll p = Y * x1 - X * y1;
	ll q = y2*x1 - x2*y1;

	assert(q);
	if (p%q) {
		return 0;
	}

	ll b = p/q;
	ll a = X - b*x2;

	assert(x1);
	if (a%x1) {
		return 0;
	}
	a = a/x1;

	if (a < 0 || b < 0) {
		return 0;
	}

	return a*3LL + b;
}

ll solve() {
	string line;
	ll ans = 0;
	while(read()) {
		ans += go();
		assert(ans >= 0);
	}
	return ans;
}

} // namespace i_want_to_use_y1


int main (void) {
	ios_base::sync_with_stdio(false);
	cout << i_want_to_use_y1::solve() << endl;
	return 0;
}
