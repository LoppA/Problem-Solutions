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

struct no{
	int n, *seg;
	vector<ii> v;
	int ay, by, a, b;

	no(){}

	no(int n) : n(n) {
		seg = new int[4*n+1];
		for(int i = 0; i < 4*n + 1; i++)
			seg[i] = 0;
		v.resize(n);
	}

	int query(int ly, int ry, int l, int r, int val){
		ay = ly;	by = ry;
		a = l;	b = r;
		return query(1, 0, v.size()-1, val);
	}

	int query(int r, int i, int j, int val){
		if (v[j] < ii(ay, a) or v[i] > ii(by, b))	return 0;

		if(v[i] >= ii(ay, a) and v[j] <= ii(by,b)){
			seg[r] = max(seg[r], val);
			return seg[r];
		} else {
			int mid = (i+j)>>1;
			int L = query(2*r, i, mid, val);
			int R = query(2*r+1, mid+1, j, val);
			seg[r] = max(seg[2*r], seg[2*r+1]);
			return max(L, R);
		}
	}
} seg[4*N+1];

int n, x[N], y[N];
vector<ii> v;

void build(int r, int i, int j){
	seg[r] = no(j-i+1);

	if(i == j){
		seg[r].v[0] = ii(v[i].se, v[i].fi);
	} else {
		int mid = (i+j)>>1;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);

		merge(seg[2*r].v.begin(), seg[2*r].v.end(),
		seg[2*r+1].v.begin(), seg[2*r+1].v.end(), seg[r].v.begin());
	}
}

int a, b, ay, by;
int query(int r, int i, int j, int val){
	if(v[j].fi < a or v[i].fi > b)	return 0;
	

	if(v[i].fi >= a and v[j].fi <= b){
		return seg[r].query(ay, by, a, b, val);
	} else {
		int mid = (i+j)>>1;
		int L = query(2*r, i, mid, val);
		int R = query(2*r+1, mid+1, j, val);
		seg[r].query(ay, by, a, b, val);
		return max(L, R);
	}
}

int main (void) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", x+i, y+i);
		v.eb(x[i], y[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	build(1, 0, v.size() - 1);

	int ans = 0;
	for(int i = 0; i < n; i++){
		a = 0;	b = x[i];
		ay = 0;	by = y[i];

		int len = query(1, 0, v.size()-1, 0);

		a = b = x[i];
		ay = by = y[i];
		query(1, 0, v.size()-1, len+1);

		ans = max(ans, len+1);
	}
	printf("%d\n", ans);

	return 0;
}
