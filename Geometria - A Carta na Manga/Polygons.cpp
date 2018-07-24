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

const int N = 1e5 + 5;

struct point {
	ll x, y;

	point() {}

	point(ll x, ll y) : x(x), y(y) {}

	point operator -(const point &B) const {
		return {x-B.x, y-B.y};
	}

	ll operator ^(const point &B) const {
		return x*B.y - y*B.x;
	}

	void read() {
		cin >> x >> y;
	}
} v[N];

int n;

bool dentro(const point &p) {
	if(((v[1]-v[0])^(p-v[0])) <= 0)
		return false;

	int bot = 2, top = n-1;
	int ans = -1;
	while(bot <= top) {
		int mid = (bot+top)>>1;

		if(((v[mid]-v[0])^(p-v[0])) < 0) {
			ans = mid;
			top = mid-1;
		} else {
			bot = mid+1;
		}
	}

	if(ans == -1)
		return false;

	if(((v[ans]-v[ans-1])^(p-v[ans-1])) <= 0)
		return false;

	return true;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	cin >> n;
	for(int i = 0; i < n; i++)
		v[i].read();

	reverse(v, v+n);

	int m;	cin >> m;
	while(m--) {
		point p;	p.read();
		if(!dentro(p)) {
			cout << "NO" << endl;
			return 0;
		}
	}

	cout << "YES" << endl;

	return 0;
}
