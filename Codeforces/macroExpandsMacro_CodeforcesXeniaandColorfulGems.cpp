#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

#define SQ(x) (x)*(x)
#define CALC(x, y, z) SQ(x-y) + SQ(y-z) + SQ(x-z)

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int n[3], i[3];
ll val[3][2];
vector<int> v[3];

void get(int id) {
	v[id] = vector<int>(n[id]);
	for(int &x : v[id])	cin >> x;
	sort(v[id].begin(), v[id].end());
}

void move(int id, int x) {
	while(i[id]+1 < n[id] and v[id][i[id]] < x)
		i[id]++;
}

void getVal(int id) {
	val[id][0] = val[id][1] = v[id][i[id]];
	if(i[id] > 0)	val[id][1] = v[id][i[id]-1];
}

inline ll calc(ll x, ll y, ll z) {
	return (x-y)*(x-y) + (y-z)*(y-z) + (x-z)*(x-z);
}

inline vector<int> merge(const vector<int> &a, const vector<int> &b) {
	vector<int> v(a.size() + b.size());
	merge(a.begin(), a.end(), b.begin(), b.end(), v.begin());
	return v;
}

void solve() {
	for(int i = 0; i < 3; i++)	cin >> n[i];
	for(int i = 0; i < 3; i++)	get(i);

	vector<int> vv = merge(v[0], v[1]);
	vv = merge(vv, v[2]);

	for(int i = 0; i < 3; i++)	::i[i] = 0;
	ll ans = LLONG_MAX;

	for(int x : vv) {
		for(int i = 0; i < 3; i++) {
			move(i, x);
			getVal(i);
		}

		for(int i = 0; i < 2; i++) 
			for(int j = 0; j < 2; j++) 
				for(int k = 0; k < 2; k++)
					ans = min(ans, CALC(val[0][i], val[1][j], val[2][k]));
	}

	cout << ans << endl;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int T;	cin >> T;
	while(T--)
		solve();

	return 0;
}
