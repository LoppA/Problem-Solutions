#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

ii p1;
ii p2;
ll a, b;

bool read() {
	string line;
	int i;

	auto parse = [&line, &i] () -> int {
		int val = 0;
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
	p1.x = parse();
	p1.y = parse();

	getline(cin, line);
	i = 0;
	p2.x = parse();
	p2.y = parse();

	getline(cin, line);
	i = 0;
	a = parse();
	b = parse();

	getline(cin, line);
	return true;
}

int go() {
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (a == i*p1.x + j*p2.x && b == i*p1.y + j*p2.y) {
				return i*3 + j;
			}
		}
	}

	return 0;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string line;
	ll ans = 0;
	while(read()) {
		ans += go();
	}
	cout << ans << endl;

	return 0;
}
