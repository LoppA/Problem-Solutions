/*

n >= k

T(n) = a1*T(n-1) + a2*T(n-2) + ... + ak*T(n-k)

 _  _     _      (n-k+1)_  _   
| Tn |   |a1 ... ak|   |Tk-1|
|Tn-1|   |1 0 0 0 0|   |Tk-2|
|Tn-2| = |0 1 0 0 0| * |Tk-3|
| ...|	 |   ...   |   | ...|
|_T1_|   |0 0 0 1 0|   |_T0_|

*/

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
const ll mod = 1e9 + 7; 
const int N = 1e5 + 5;

class mat {
public:
	ll m[2][2];

	mat () {
		m[0][0] = 1;
		m[0][1] = 0;
		m[1][0] = 0;
		m[1][1] = 1;
	}

	mat (ll a, ll b, ll c, ll d) {
		m[0][0] = a;
		m[0][1] = b;
		m[1][0] = c;
		m[1][1] = d;
	}

	mat operator * (const mat &B) const {
		mat ret = mat(0,0,0,0);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 2; k++) {
					ret.m[i][j] += (m[i][k] * B.m[k][j])%mod;
					ret.m[i][j] %= mod;
				}
			}
		}
		return ret;
	}

};

pair <ll, ll> v[N], seg[4*N + 1];
mat lazy[4*N + 1];
int a, b, n, m, op;

ostream &operator<< (ostream &os, mat const &M) {
	return os << M.m[0][0] << " " << M.m[0][1] << endl << M.m[1][0] << " " << M.m[1][1] << endl;
}

mat exp (ll y) {
	mat R, A = mat(1,1,1,0);
	mat T = A;

	while (y) {
		if ((y & 1)) {
			R = R * T;
		}
		T = T * T;
		y >>= 1;
	}

	return R;
}

pair<ll, ll> sum (pair<ll, ll> p1, pair<ll, ll> p2) {
	return mk((p1.fi + p2.fi)%mod, (p1.se + p2.se)%mod);
}

pair<ll,ll> build (int r, int i, int j) {
	int m = (i+j)/2;
	if (i == j) {
		seg[r] = v[i];
	} else {
		seg[r] = sum(build(2*r, i, m), build(2*r+1, m+1, j));
	}
	return seg[r];
}

void prop (int r, int i, int j) {
	mat f = lazy[r];
	lazy[r] = mat();

	seg[r] = mk(f.m[0][0]*seg[r].fi + f.m[0][1]*seg[r].se, 
	f.m[1][0]*seg[r].fi + f.m[1][1]*seg[r].se);

	seg[r].fi = (seg[r].fi)%mod;
	seg[r].se = (seg[r].se)%mod;

	if (i == j)
		return;
	
	lazy[2*r] = lazy[2*r] * f;
	lazy[2*r + 1] = lazy[2*r + 1] * f;
}

mat mt;
void update (int r, int i, int j) {
	int m = (i + j)/2;
	prop(r, i, j);

	if (j < a or i > b)	return;

	if (i >= a and j <= b) {
		lazy[r] = mt;
		prop(r, i, j);
	} else {
		update(2*r, i, m);
		update(2*r + 1, m + 1, j);
		seg[r] = sum(seg[2*r], seg[2*r+1]);
	}
}

ll query (int r, int i, int j) {
	int m = (i + j)/2;
	prop(r, i, j);

	if (j < a or i > b)	return 0;

	if (i >= a and j <= b) {
		return seg[r].se;
	} else {
		ll L = query(2*r, i, m);
		ll R = query(2*r + 1, m+1, j);
		return (L + R)%mod;
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);

/*	ll a;
	while (cin >> a) {
		mat f = exp(max(a-1,0LL));

		ll res = f.m[1][0] + f.m[1][1];

//		cout << a << endl << f;
		cout << res << endl;
	}*/

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		ll a;	cin >> a;
		mat f = exp(max(a-1, 0LL));
		v[i] = mk(f.m[0][0] + f.m[0][1], f.m[1][0] + f.m[1][1]);
	}

	build (1, 0, n-1);
	
	while (m--) {
		cin >> op;
		if (op == 1) {
			int val;
			cin >> a >> b >> val;
			a--;	b--;
			mt = exp(ll(val));
			update (1, 0, n-1);
		} else {
			cin >> a >> b;
			a--;	b--;
			cout << query(1, 0, n-1) << endl;
		}
	}

	return 0;
}
