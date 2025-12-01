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
	const string r_mul = "mul\\(\\d{1,3},\\d{1,3}\\)";
	const string r_on = "do\\(\\)";
	const string r_off = "don't\\(\\)";
	regex r(r_mul + "|" + r_on + "|" + r_off);

	bool enabled = true;
	ll ans = 0;
	sregex_iterator reg_beg = sregex_iterator(s.begin(), s.end(), r);
	sregex_iterator reg_end = sregex_iterator();
	for (sregex_iterator it = reg_beg; it != reg_end; it++) {
		// cout << it->str() << endl;
		if (regex_match(it->str(), regex(r_on))) {
			// cout << "ON" << endl;
			enabled = true;
		} else if (regex_match(it->str(), regex(r_off))) {
			// cout << "OFF" << endl;
			enabled = false;
		} else if (enabled) {
			ans += process(it->str());
		}
	}
	
	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string s, line;
	while(getline(cin, line)) {
		s += line;
	}
	cout << go(s) << endl;

	return 0;
}
