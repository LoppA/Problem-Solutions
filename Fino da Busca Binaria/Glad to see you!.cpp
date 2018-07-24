#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n, k;

bool go(int x) {
	assert(x >= 1 and x <= n and x +1 >= 1 and x + 1 <= n);
	cout << "1 " << x << " " << x + 1 << endl;
	fflush(stdout);
	string s;	cin >> s;
	fflush(stdout);

	return (s == "TAK");
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n >> k;
	fflush(stdout);

	int bot = 1, top = n - 1;
	int r1 = 1;
	while(bot <= top) {
		int mid = (bot + top)>>1;

		if(go(mid)) {
			r1 = mid;
			top = mid - 1;
		} else {
			r1 = mid + 1;
			bot = mid + 1;
		}
	}

	bot = 1;
	top = r1 - 1;
	int r2 = n;

	while(bot <= top) {
		int mid = (bot + top)>>1;

		if(go(mid)) {
			r2 = mid;
			top = mid - 1;
		} else {
			bot = mid + 1;
		}
	}

	bot = r1 + 1;
	top = n - 1;

	while(bot <= top) {
		int mid = (bot + top + 1)>>1;

		if(go(mid)) {
			r2 = mid;
			top = mid - 1;
		} else {
			r2 = mid + 1;
			bot = mid + 1;
		}
	}

	assert(r1 >= 1 and r1 <= n and r2 >= 1 and r2 <= n);
	assert(r1 != r2);
	cout << "2 " << r1 << " " << r2 << endl;

	return 0;
}
