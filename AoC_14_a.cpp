#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second

typedef long long ll;
typedef __int128 LL;
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const ll N = 101, M = 103, T = 100;
vector<ii> p, v;

void read() {
	string line;
	int i;

	auto parse = [&line, &i] () -> ll {
		ll val = 0;
		int sig = 1;
		bool f = false;
		while(i < (int)line.size()) {
			char c = line[i++];
			if (c == '-') {
				sig = -1;
			} else if (c >= '0' && c <= '9') {
				f = true;
				val = val*10 + c-'0';
			} else if (f) {
				return val*sig;
			}
		}
		return val*sig;
	};

	auto parse_pair = [&] () -> ii {
		ll x = parse();
		ll y = parse();
		return {x, y};
	};

	while(getline(cin, line)) {
		i = 0;
		p.emplace_back(parse_pair());
		v.emplace_back(parse_pair());
	}
}

ii go(ii p, ii v) {
	ll x = (p.x + v.x * T)%N;
	ll y = (p.y + v.y * T)%M;

	if (x < 0) {
		x += N;
	}
	if (y < 0) {
		y += M;
	}

	return {x, y};
}

ll go() {
	assert(v.size() == p.size());

	int n = v.size();
	ll cnt[2][2] = {0};


	for (int i = 0; i < n; i++) {
		ii pos = go(p[i], v[i]);

		if (pos.x == N/2 || pos.y == M/2) {
			cout << "NO" << endl;
			continue;
		}

		cnt[pos.x > N/2][pos.y > M/2]++;
	}

	ll ans = 1;
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			ans *= cnt[i][j];
		}
	}

	return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	read();
	cout << go() << endl;

	return 0;
}
