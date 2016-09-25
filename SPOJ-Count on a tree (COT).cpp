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
 
const int N = 1e5 + 5;
const int M = 3e6 + 7;
int n, m, nodes;
ll w[N];
int id[N];
vector <int> g[N];
ll v[M], R[M], L[M], root[N];

class LCA {
public:
	int pai[N][20], dist[N];

	void build (int curr){
		for (int i = 1; i < 20; i++){
				pai[curr][i] = pai[pai[curr][i-1]][i-1];
		}
	}

	void ini (int curr, int last, int d){
		dist[curr] = d;
		pai[curr][0] = last;
		build (curr);

		for (unsigned int i = 0; i < g[curr].size(); i++){
				int next = g[curr][i];
				if (next != last) ini (next, curr, d+1);
		}
	}


	int query (int u, int v){
		if (dist[v] < dist[u])
		swap(v,u);

		while (dist[u] < dist[v]){
				int i = 0;
				while (dist[pai[v][++i]] > dist[u]);
				v = pai[v][i-1];
		}
		if (u == v) return u;

		while (pai[u][0] != pai[v][0]){
				int i = 0;
				while (pai[v][i] != pai[u][i]){
						i++;
				}
				v = pai[v][i-1];
				u = pai[u][i-1];
		}
		return pai[v][0];
	}
} lca;

int build (int l, int r) {
	int j = nodes++;
	if (l == r) {
		v[j] = 0;
	} else {
		int m = (l+r)/2;
		L[j] = build(l, m);
		R[j] = build(m + 1, r);
		v[j] = v[L[j]] + v[R[j]];
	}
	return j;
}

int update (int i, int l, int r, int p, int c) {
	int j = nodes++;
	int m = (l + r)/2;

	if (l == r) {
		v[j] = c;
		return j;
	}

	if (p <= m) {
		L[j] =  update(L[i], l, m, p, c);
		R[j] = R[i];
	} else {
		L[j] = L[i];
		R[j] =  update(R[i], m + 1, r, p, c);
	}
	v[j] = v[L[j]] + v[R[j]];
	return j;
}
 
void dfs (int pai, int at) {
	root[at] = update (root[pai], 1, n, id[at], 1);

	for (int i = 0; i < (int)g[at].size(); i++) {
		int next = g[at][i];
		if (next != pai)
			dfs (at, next);
	}
} 

int query (int i, int j, int a, int b, int l, int r, int c) {
//	cout << v[i] << " " << v[j] << " " << v[a] << " " << v[b] << endl;
	if (l == r) {
		return l;
	}

	int nl = v[L[i]] + v[L[j]] - v[L[a]] - v[L[b]];
	int m = (l + r)/2;

	if (c <= nl)
		return query(L[i], L[j], L[a], L[b], l, m, c);

	return query(R[i], R[j], R[a], R[b], m+1, r, c-nl);
}
 
int main (void) {
//	ios_base::sync_with_stdio(false);
 
	scanf("%d %d", &n, &m);
 
	vector <ii> v;
	for (int i = 1; i <= n; i++)  {
		scanf("%lld", w + i);
		v.pb(mk(w[i], i));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; i++) {
		w[v[i].se] = i + 1;
		id[v[i].se] = i + 1;
	}

//	for (int i = 1; i <= n; i++) 
//		cout << i << " " << w[i] << endl;
	
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
 
	root[0] = build(1, n);
	lca.ini(1, 0, 0);
 
	dfs (0, 1);

	while (m--) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		int pp = lca.query(a, b);
//		cout << a << " " << b << " " << pp << " " << lca.pai[pp][0] << endl;
		int i = query (root[a], root[b], root[pp], root[lca.pai[pp][0]], 1, n, c);
//		cout << i << endl;
		printf("%d\n", v[i-1].fi);
	}
 
	return 0;
}
 
