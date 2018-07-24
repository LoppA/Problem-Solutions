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

void yes() {
	cout << "YES" << endl;
	exit(0);
}

const int N = 1e5 + 5;
ll x[N], y[N], n;

ll cross(ll x1, ll y1, ll x2, ll y2) {
	return x1*y2 - y1*x2;
}

bool linha(int a, int b, int c) {
	ll vx = x[a] - x[b];
	ll vy = y[a] - y[b];

	ll _vx = x[a] - x[c];
	ll _vy = y[a] - y[c];

	return !cross(vx, vy, _vx, _vy);
}

bool v[N];
void _go(int a, int b, int c) {
	memset(v, 0, sizeof v);

	v[a] = v[b] = 1;
	int d = -1;
	for(int i = 0; i < n; i++) {
		if(i == a or i == b or i == c)	continue;

		if(linha(a, b, i))
			v[i] = 1;
		else
			d = i;
	}

	if(d == -1)	yes();

	for(int i = 0; i < n; i++) {
		if(i == c or i == d)	continue;
		if(v[i])	continue;

		if(!linha(c, d, i))
			return;
	}

	yes();
}

void go(int a, int b, int c) {
	_go(a, b, c);
	_go(a, c, b);
	_go(b, c, a);
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	for(int i = 2; i < n; i++) {
		if(!linha(0, 1, i)) {
			go(0, 1, i);
			cout << "NO" << endl;
			return 0;
		}
	}

	yes();

	return 0;
}
