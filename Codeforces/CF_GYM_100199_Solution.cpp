/*  O (V^2 * E)
	Implementacao mais facil pra recuperar o flow
*   
*   MinCut tutorial:
*   
*	Grafo do flow G
*	MinCut: corte de G em S - T, s pertence a S e t pertence a T
*
*	MinCut = MaxFlow
*
*	Todos os vertices alcancaveis por s no grafo residual final
*	pertence a S o resto pertence a T
*
*	As arestas de MinCut sao todas que ligam S a T
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

struct edge {
	int to, cap, flow, rid;

	edge () {}

	edge (int a, int b, int c, int d) : 
		to(a), cap(b), flow(c), rid(d) {}
};

const int N = 210;
vector <edge> g[N];

void add (int a, int b, int c) {
	g[a].pb(edge(b, c, 0, g[b].size()));
	g[b].pb(edge(a, 0, 0, g[a].size() - 1));
}

ii pai[N];
int bfs (int s, int t) {
	for (int i = 0; i < N; i++)
		pai[i] = ii(-1, -1);
	queue <ii> q;
	q.push(ii(s, INF));

	while (!q.empty()) {
		int at = q.front().fi;
		int free = q.front().se;
		q.pop();

		for (int i = 0 ; i < (int)g[at].size(); i++) {
			edge edg = g[at][i];
			if (pai[edg.to].fi == -1 and edg.cap - edg.flow > 0) {
				int f = min(edg.cap - edg.flow, free);
				q.push(ii(edg.to, f));
				pai[edg.to] = ii(at, i);
				if (edg.to == t)
					return f;
			}
		}
	}
	return 0;
}

int max_flow (int s, int t) {
	int ret = 0;
	while (1) {
		int f = bfs (s, t);

		if (!f) break;

		for (int at = t; at != s; at = pai[at].fi) {
			edge &edg = g[pai[at].fi][pai[at].se];
			edg.flow += f;

			edge &redg = g[edg.to][edg.rid];
			redg.flow -= f;
		}

		ret += f;
	}
	return ret;
}

int S = N - 1, T = N - 2;
int d[N], res[N*N];
map <ii, ii> mp;
map <ii, int> flow;

int main (void) {
	ios_base::sync_with_stdio(false);

	freopen ("cooling.in", "r", stdin);
	freopen ("cooling.out", "w+", stdout);

	int n, m;	cin >> n >> m;

	for (int k = 0; k < m; k++) {
		int i, j, l, c;
		cin >> i >> j >> l >> c;
		add (i, j, c - l);
		d[i] += l;
		d[j] -= l;
		mp[ii(i,j)] = ii(k, l);
	}
	
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] > 0) {
			add (i, T, d[i]);
			sum += d[i];
		} else if (d[i] < 0) {
			add (S, i, -d[i]);
		}
	}

	if (max_flow (S, T) != sum)	{
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;

		for (int i = 1; i <= n; i++) 
			for (auto j : g[i]) 
				flow[ii(i, j.to)] =  j.flow;
			
		for (auto it : mp) 
			res[it.se.fi] = it.se.se + flow[it.fi];

		for (int i = 0; i < m; i++)
			cout << res[i] << endl;
	}

	return 0;
}
