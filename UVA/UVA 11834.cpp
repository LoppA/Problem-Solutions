#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double E = exp(1);

double l, c, r1, r2;
char ans[2] = {'N', 'S'};

bool go (double a, double b) {
	if (b < 2.0*r1 or a < 2.0*r1) return false;

	double ang1 = PI/2.0;

	if (b < 2.0*r1 + 2.0*r2) {
		ang1 = asin( (b - r1 - r2) / (r1 + r2) );
	}

	double ang2 = 0.0;

	if (a < 2.0*r1 + 2.0*r2) {
		ang2 = acos( (a - r1 - r2) / (r1 + r2) );
	}

	return ang1 >= ang2;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	while (cin >> l >> c >> r1 >> r2, l) {
		if (r1 < r2) swap(r1,r2);
		cout << ans[(go(l,c) or go(c,l))] << endl;
	}

	return 0;
}
