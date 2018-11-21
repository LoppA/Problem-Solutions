// https://codeforces.com/gym/101964/problem/K
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back

typedef pair<int, int> ii;
typedef long long ll;

const int N = 1e5 + 5;

struct query{
	int t, x1, x2, y1, y2;

	query(){}

	void read(){
		scanf("%d", &t);
		scanf("%d %d", &x1, &y1);
		if(t == 2)
			scanf("%d %d", &x2, &y2);
	}
} qr[N];

struct no{
	int *seg, *lazy;
	vector<ii> v;
	int n;
	int ay, by, a, b;

	no(){}

	no(int n) : n(n){
		seg = new int [4*n+1];
		lazy = new int [4*n+1];
		for(int i = 0; i < 4*n + 1; i++)
			seg[i] = lazy[i] = 0;
		v.resize(n);
	}

	int query(int ly, int ry, int l, int r, int val) {
		ay = ly;	by = ry;
		a = l;	b = r;
		return query(1, 0, n-1, val);
	}

	void prop(int r, int i, int j){
		seg[r] += lazy[r];
		if(i != j){
			lazy[2*r] += lazy[r];
			lazy[2*r+1] += lazy[r];
		}
		lazy[r] = 0;
	}

	int query(int r, int i, int j, int val){
		prop(r, i, j);
		if(v[j] < ii(ay, a) or v[i] > ii(by, b))	return 0;

		if(v[i] >= ii(ay, a) and v[j] <= ii(by, b)){
			lazy[r] += val;
			prop(r, i, j);
			return seg[r];
		} else {
			int mid = (i + j)>>1;
			int L = query(2*r, i, mid, val);
			int R = query(2*r+1, mid+1, j, val);
			seg[r] = seg[2*r] + seg[2*r+1];
			return L + R;
		}
	}
};

vector<ii> v;
int n;

no seg1[4*N+1], seg2[4*N+1];

void build(int r, int i, int j){
	seg1[r] = no(j - i + 1);
	seg2[r] = no(j - i + 1);

	if(i == j){
		seg1[r].v[0] = seg2[r].v[0] = ii(v[i].se, v[i].fi);
	} else {
		int mid = (i + j)>>1;
		build(2*r, i, mid);
		build(2*r+1, mid+1, j);

		merge(seg1[2*r].v.begin(), seg1[2*r].v.end(), seg1[2*r+1].v.begin(), seg1[2*r+1].v.end(), seg1[r].v.begin());
		merge(seg2[2*r].v.begin(), seg2[2*r].v.end(), seg2[2*r+1].v.begin(), seg2[2*r+1].v.end(), seg2[r].v.begin());
	}
}

ll ans = 0;
int a, b, ay, by;

void update1(int r, int i, int j){
	if(v[j].fi < a or v[i].fi > b)	return;

	seg1[r].query(ay, by, a, b, 1);

	if(i == j)
		return;

	int mid = (i+j)>>1;
	update1(2*r, i, mid);
	update1(2*r+1, mid+1, j);
}

int query1(int r, int i, int j){
	if(v[j].fi < a or v[i].fi > b)	return 0;

	if(v[i].fi >= a and v[j].fi <= b){
		return seg1[r].query(ay, by, a, b, 0);
	} else {
		int mid = (i+j)>>1;
		int L = query1(2*r, i, mid);
		int R = query1(2*r+1, mid+1, j);
		return L + R;
	}
}

void update2(int r, int i, int j){
	if(v[j].fi < a or v[i].fi > b)	return;

	if(v[i].fi >= a and v[j].fi <= b){
		seg2[r].query(ay, by, a, b, 1);
	} else {
		int mid = (i+j)>>1;
		update2(2*r, i, mid);
		update2(2*r+1, mid+1, j);
	}
}

int query2(int r, int i, int j){
	if(v[j].fi < a or v[i].fi > b)	return 0;


	int ret = seg2[r].query(ay, by, a, b, 0);

	if(i == j)
		return ret;
	
	int mid = (i+j)>>1;
	ret += query2(2*r, i, mid);
	ret += query2(2*r+1, mid+1, j);
	return ret;
}

int main() {
	int q;	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		qr[i].read();
		if(qr[i].t == 1)
			v.pb(ii(qr[i].x1, qr[i].y1));
	}

	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	n = v.size();

	build(1, 0, n-1);

	for(int i = 0; i < q; i++){
		if(qr[i].t == 1){
			a = b = qr[i].x1;
			ay = by = qr[i].y1;
			update1(1, 0, n-1);
			ans += query2(1, 0, n-1);
		} else {
			a = qr[i].x1;
			b = qr[i].x2;
			ay = qr[i].y1;
			by = qr[i].y2;
			update2(1, 0, n-1);
			ans += query1(1, 0, n-1);
		}

		printf("%lld\n", ans);
	}
	
	return 0;
}
