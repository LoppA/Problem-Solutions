#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;

template <typename T>
std::ostream& operator<< (std::ostream& out, const vector<T>& v) {
    out << '[';
    bool f = false;
    for(auto& x:v){
      if (f)  out<<", ";
      f = true;
      out<<x;
    }
    out << "]";
    return out;
}
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
  vector<string> __attribute__ ((unused)) args,
  __attribute__ ((unused)) int idx,
  __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}

#ifdef DEBUG 
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define debug_endl() cout << endl;
#else
#define debug(...) 42
#define debug_endl(...) 42
#endif


struct Edge {
  int next;
  int rid;
  bool ponte;

  Edge (int next, int rid) :
    next(next), rid(rid), ponte(false) {}
};

const int N = 3e5 + 5, LOG = 22;

int n, m;
int id[N];
bool odd[N];

namespace raw {
	bool vis[N];
	vector <Edge> g[N];
	int entra[N], sai[N], low[N];
	int t;

  void clear() {
    memset(vis, 0, sizeof vis);
    memset(id, 0, sizeof id);
    memset(odd, 0, sizeof odd);
    memset(sai, 0, sizeof sai);
    memset(entra, 0, sizeof entra);
    memset(low, 0, sizeof low);
    for (int i = 0; i < N ; i++) {
      g[i].clear();
    }
		t = 0;
  }

  void add(int u, int v) {
    g[u].eb(v, g[v].size());
    g[v].eb(u, g[u].size()-1);
  }

	void dfs (int at, int pai) {
		vis[at] = true;
		low[at] = entra[at] = t++;

		for (Edge &e : g[at]) {
      int next = e.next;
			if (!vis[next]) {
				dfs(next, at);
				low[at] = min(low[next], low[at]);
				if (low[next] > entra[at]) {
          e.ponte = true;
          g[next][e.rid].ponte = true;
        }
			} else if (next != pai) {
				low[at] = min(low[at], entra[next]);
			}
    }
		
		sai[at] = t++;
	}

  int color[N];

  bool bicolor(int u) {
    int f = true;

    for (const Edge &e : g[u]) {
      if (e.ponte) {
        continue;
      }
      int v = e.next;
      if (color[v] == -1) {
        color[v] = 1 - color[u];
        id[v] = id[u];
        f &= bicolor(v);
      } else if (color[u] == color[v]) {
        f = false;
      }
    }

    return f;
  }

  void bicolorAll() {
    memset(color, -1, sizeof color);

    for (int u = 1; u <= n; u++) {
      if (color[u] == -1) {
        color[u] = 0;
        id[u] = u;
        odd[u] = !bicolor(u);
      }
    }
  }

} // namespace raw

vector<int> g[N];
int dist[N];

namespace graph {

  void clear() {
    for (int i = 0; i < N; i++) {
      g[i].clear();
    }
  }

  void build() {
    for (int u = 1; u <= n; u++) {
      for (const Edge &e : raw::g[u]) {
        if (e.ponte) {
          g[id[u]].pb(id[e.next]);
        }
      }
    }
  }

  bool bfs() {
    memset(dist, -1, sizeof dist);
    queue<int> q;

    for (int u = 1; u <= n; u++) {
      if (odd[u]) {
        q.push(u);
        dist[u] = 0;
      }
    }

    if (!q.size()) {
      return false;
    }

    while(q.size()) {
      int u = q.front();
      q.pop();

      for (int v : g[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u]+1;
          q.push(v);
        }
      }
    }

    return true;
  }

} // namespace graph

namespace tree {
  int p[N][LOG], val[N][LOG];
  int lvl[N];

  void clear() {
    memset(p, 0, sizeof p);
    memset(val, 0, sizeof val);
    memset(lvl, 0, sizeof lvl);
  }

  void lift(int u) {
    for (int i = 1; i < LOG; i++) {
      int _p = p[u][i-1];
      p[u][i] = p[_p][i-1];
      val[u][i] = min(val[u][i-1], val[_p][i-1]);
    }
  }

  void build(int at, int pai = 0) {
    lvl[at] = lvl[pai]+1;
    p[at][0] = pai;
    val[at][0] = dist[pai];

    lift(at);

    for (int next : g[at]) {
      if (next == pai || lvl[next]) {
        continue;
      }
      build(next, at);
    }
  }

  int query(int u, int v) {
    int d = min(dist[u], dist[v]);
    if (lvl[u] > lvl[v]) {
      swap(u, v);
    }

    for (int i = LOG-1; i >= 0; i--) {
      int _v = p[v][i];
      if (lvl[_v] >= lvl[u]) {
        d = min(d, val[v][i]);
        v = _v;
      }
    }

    if (u == v) {
      return d;
    }

    for (int i = LOG-1; i >= 0; i--) {
      int _u = p[u][i], _v = p[v][i];
      if (_u != _v) {
        d = min(d, min(val[u][i], val[v][i]));
        u = _u;
        v = _v;
      }
    }

    d = min(d, val[u][0]);

    return d;
  }

} // namespace tree

ll go() {
  raw::clear();
  graph::clear();
  tree::clear();

  cin >> n >> m;

  while(m--) {
    int u, v; cin >> u >> v;
    raw::add(u, v);
  }

  raw::dfs(1, 0);
  raw::bicolorAll();

  graph::build();
  bool no = !graph::bfs();

  dist[0] = n;
  for (int i = 0; i < LOG; i++) {
    tree::val[0][i] = n;
  }
  tree::build(1);

  debug_endl();
  int q;  cin >> q;
  ll ans = no ? -q : 0;
  while(q--) {
    int u, v; cin >> u >> v;

    if (no) {
      continue;
    }

    int d = tree::query(id[u], id[v]);
    ans += d;

    debug(u, v, id[u], id[v], d);
  }

  debug_endl();
  debug("RAW");
  for (int i = 1; i <= n; i++) {
    debug(i, id[i], odd[i]);
  }

  debug_endl();
  debug("GRAPH");
  for (int i = 1; i <= n; i++) {
    if (i != id[i]) continue;
    debug(i, dist[i], g[i]);
  }


  return ans;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    cout << go() << endl;
  }

  return 0;
}

