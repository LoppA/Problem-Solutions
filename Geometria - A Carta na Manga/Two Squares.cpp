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

void yes() {
	cout << "YES" << endl;
	exit(0);
}

struct Point {
	ll x, y;

	Point() {}

	Point(ll x, ll y) : x(x), y(y) {}

	void read() {
		cin >> x >> y;
	}

	Point operator - (const Point &B) const {
		return {x-B.x, y-B.y};
	}

	ll operator ^ (const Point &B) const {
		return x*B.y - y*B.x;
	}
} v1[4], v2[4];

bool inter(Point a, Point b, Point c, Point d) {
	Point v = b - a;
	Point u1 = c - a;
	Point u2 = d - a;

	if((v^u1) * (v^u2) > 0)
		return false;

	v = d - c;
	u1 = a - c;
	u2 = b - c;

	if((v^u1) * (v^u2) > 0)
		return false;

	return true;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	for(int i = 0; i < 4; i++)
		v1[i].read();

	for(int i = 0; i < 4; i++)
		v2[i].read();

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			int ii = (i + 1)%4;
			int jj = (j + 1)%4;

			if(inter(v1[ii], v1[i], v2[jj], v2[j]))
				yes();
		}
	}

	bool f = true;
	ll sig = 0;
	for(int i = 0; i < 4; i++) {
		int ii = (i + 1)%4;
		Point v = v1[ii] - v1[i];
		Point u = v2[0] - v1[i];

		if((v^u) == 0)	continue;

		if(sig == 0)
			sig = (v^u);
		else if (sig*(v^u) < 0)
			f = false;
	}

	if(f)
		yes();

	f = true;
	sig = 0;
	for(int i = 0; i < 4; i++) {
		int ii = (i + 1)%4;
		Point v = v2[ii] - v2[i];
		Point u = v1[0] - v2[i];

		if((v^u) == 0)	continue;

		if(sig == 0)
			sig = (v^u);
		else if (sig*(v^u) < 0)
			f = false;
	}

	if(f)
		yes();

	cout << "NO" << endl;

	return 0;
}
