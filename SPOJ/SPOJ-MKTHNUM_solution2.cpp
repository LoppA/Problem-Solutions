/*
https://www.spoj.com/problems/MKTHNUM/
With Persistent SegTree
*/

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

const int N = 1e5 + 5, M = 2e6 + 6;
int n, a[N];

int root[N], L[M], R[M], seg[M];
int nodes;

int build(int i, int j) {
	int at = ++nodes;
	
	seg[at] = 0;

	if(i != j) {
		int mid = (i+j)>>1;
		L[at] = build(i, mid);
		R[at] = build(mid+1, j);
	}

	return at;
}

int update(int nd, int i, int j, int p) {
	int at = ++nodes;

	if(i == j) {
		seg[at] = seg[nd] + 1;
	} else {
		int mid = (i+j)>>1;
		if(p <= mid) {
			L[at] = update(L[nd], i, mid, p);
			R[at] = R[nd];
		} else {
			L[at] = L[nd];
			R[at] = update(R[nd], mid+1, j, p);
		}

		seg[at] = seg[L[at]] + seg[R[at]];
	}

	return at;
}

int query(int l, int r, int i, int j, int k) {
	if(i == j) {
		return i;
	} else {
		int cnt_l = seg[L[r]] - seg[L[l]];
		int mid = (i+j)>>1;

		if(k <= cnt_l)
			return query(L[l], L[r], i, mid, k);
		return query(R[l], R[r], mid+1, j, k-cnt_l);
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int m;
	cin >> n >> m;
	vector<int> v;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	map<int, int> mp;
	for(int i = 0; i < (int)v.size(); i++)
		mp[v[i]] = i;
	for(int i = 0; i < n; i++)
		a[i] = mp[a[i]];

	root[0] = build(0, n-1);
	for(int i = 0; i < n; i++)
		root[i+1] = update(root[i], 0, n-1, a[i]);

	while(m--) {
		int l, r, k;	cin >> l >> r >> k;
		int i = query(root[l-1], root[r], 0, n-1, k);
		cout << v[i] << endl;
	}

	return 0;
}
