#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ll process(string s) {
	int i = 0;

	auto parse = [&i, &s]() -> int {
		bool f = false;
		int val = 0;
		while(i < (int)s.size()) {
			char c = s[i++];
			if (c >= '0' && c <= '9') {
				f = true;
				val = val*10 + c-'0';
			} else {
				if (f) {
					return val;
				}
			}
		}
		return val;
	};

	ll a = parse();
	ll b = parse();

	// cout << s << endl;
	// cout << a << " " << b << endl;

	return a*b;
}

ll go(string s) {
	regex r("mul\\(\\d{1,3},\\d{1,3}\\)");

	
	sregex_iterator reg_beg = sregex_iterator(s.begin(), s.end(), r);
	sregex_iterator reg_end = sregex_iterator();

	ll ans = 0;
	for (sregex_iterator it = reg_beg; it != reg_end; it++) {
		ans += process(it->str());
	}
	
	return ans;
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
