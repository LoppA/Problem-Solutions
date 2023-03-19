// Problem: https://codeforces.com/contest/1806/problem/E
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

const int N = 2e5 + 5, S = 320, Q = 1e5 + 5, LOG = 21;
int n, m;

class Tree {
private:
  int pai[N][LOG];
  int t;

  void build(int u) {
    for (int i = 1; i < LOG; i++) {
      int _pai = pai[u][i-1];
      pai[u][i] = pai[_pai][i-1];
    }
  }

  void init(int u, int p) {
    st[u] = t++;

    pai[u][0] = p;
    build(u);

    for (int v : g[u]) {
      if (v != p) {
        acc[v] = acc[u] + w[v]*w[v];
        dist[v] = dist[u] + 1;
        init(v, u);
      }
    }

    en[u] = t++;
  }

public:
  vector<int>g[N];
  int dist[N];
  int st[N], en[N];
  ll w[N];
  ll acc[N];

  void build() {
    acc[1] = w[1] * w[1];
    dist[1] = 0;
    t = 0;
    init(1, 0);
  }

  void add(int u, int v) {
    g[u].pb(v);
    g[v].pb(u);
  }

  int lca(int u, int v){
    if (dist[v] < dist[u])
      swap(v,u);

    int x = dist[v] - dist[u];

    for (int i = 0; i < LOG; i++)
      if (x & (1<<i))
        v = pai[v][i];

    if (u == v) return u;

    for (int i = LOG - 1; i >= 0; i--)
      if (pai[u][i] != pai[v][i]) {
        u = pai[u][i];
        v = pai[v][i];
      }

    return pai[u][0];
  }

} t;

class Query {
public:
  int u, v, lca;
  int l, r;
  int id;

  Query() {}

  void build() {
    if (t.st[u] > t.st[v]) {
      swap(u, v);
    }
    lca = t.lca(u, v);
    if (lca == u) {
      l = t.st[u];
      r = t.st[v];
    } else {
      l = t.en[u];
      r = t.st[v];
    }
  }

  bool operator < (const Query& other) const {
    int i = l/S, j = other.l/S;
    if (i != j) {
      return i < j;
    }
    return r < other.r;
  }
};

class Mo {
public:
  vector<Query> v;
  ll res, ans[Q];
  int freq[N];
  int distCnt[N];
  ll distVal[N];
  int no[N];

  Mo(int m) {
    v = vector<Query>(m);
    int i = 0;
    for (Query &q : v) {
      cin >> q.u >> q.v;
      q.id = i++;
      q.build();
    }
    for (int i = 1; i <= n; i++) {
      no[t.st[i]] = i;
      no[t.en[i]] = i;
    }
    for (int i = 0; i < N; i++) {
      distVal[i] = 1;
    }
  }

  void _add(int i) {
    int d = t.dist[i];

    distCnt[d]++;
    distVal[d] *= t.w[i];
    if (distCnt[d] == 2) {
      res += distVal[d];
    }
  }

  void _remove(int i) {
    int d = t.dist[i];

    if (distCnt[d] == 2) {
      res -= distVal[d];
    }
    distCnt[d]--;
    distVal[d] /= t.w[i];
  }

  void add(int id) {
    if (id < 0) return;


    int i = no[id];

    freq[i]++;
    if (freq[i] == 1) {
      _add(i);
    } else {
      _remove(i);
    }
  }

  void remove(int id) {
    if (id < 0) return;

    int i = no[id];

    freq[i]--;
    if (freq[i] == 1) {
      _add(i);
    } else {
      _remove(i);
    }
  }

  void solve() {
    sort(v.begin(), v.end());
    res = 0;

    int l = -1, r = -1;
    for (const Query& q : v) {
      if (q.u == q.v) {
        ans[q.id] = t.acc[q.u];
        continue;
      }

      while(r < q.r) {
        r++;
        add(r);
      }
      while(l < q.l) {
        remove(l);
        l++;
      }

      while(l > q.l) {
        l--;
        add(l);
      }
      while(r > q.r) {
        remove(r);
        r--;
      }

      int l = q.lca;
      if (q.lca != q.u) {
        ans[q.id] = res + t.acc[l];
      } else {
        ll w = t.w[l];
        ans[q.id] = res + t.acc[l] - w*w;
      }
    }
  }

  void print() {
    for (int i = 0; i < m; i++) {
      cout << ans[i] << endl;
    }
  }

};

int main (void) {
  ios_base::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> t.w[i];
  }
  for (int v = 2; v <= n; v++) {
    int u;  cin >> u;
    t.add(u, v);
  }
  t.build();

  Mo mo(m);
  mo.solve();
  mo.print();

  return 0;
}

