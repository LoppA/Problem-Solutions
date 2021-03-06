/*Mais facil pra recuperar o flow*/
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

const int N = 111;
vector <edge> g[N];

void add (int a, int b, int c) {
	g[a].pb(edge(b, c, 0, g[b].size()));
	g[b].pb(edge(a, c, 0, g[a].size() - 1));
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

bool vis[N];
void go (int at) {
	vis[at] = 1;

	for (int i = 0; i < (int)g[at].size(); i++) {
		edge edg = g[at][i];
		int next = edg.to;
		if (!vis[next] and edg.cap - edg.flow)
			go (next);
	}
}

bool pao[N];
void imp (int at) {
	pao[at] = 1;

	for (int i = 0; i < (int)g[at].size(); i++) {
		edge edg = g[at][i];
		int next = edg.to;
		if (!vis[next]) 
			cout << at << " " << next << endl;
		else if (!pao[next])
			imp (next);
	}
}

int main (void) {

	int n, m;
	while (cin >> n >> m and n) {
		for (int i = 0; i < N; i++)
			g[i].clear();
		memset (vis, 0, sizeof vis);
		memset (pao, 0, sizeof pao);
		while (m--) {
			int a, b, w;	cin >> a >> b >> w;
			add (a, b, w);
		}
		max_flow(1, 2);
		go (1);
		imp (1);
		cout << endl;
	}

	return 0;
}
