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
	vector<int> l, r;
	while (cin >> a >> b) {
		l.push_back(a);
		r.push_back(b);
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	ll ans = 0;
	for (int i = 0; i < (int)l.size(); i++) {
		ans += abs(l[i] - r[i]);
	}

	cout << ans << endl;

	return 0;
}
