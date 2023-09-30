// https://codeforces.com/contest/1797/problem/E
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

const int N = 5e6 + 5, M = 1e5+5, LOG = 6;
int n, m, a[M];
ll phi[N];

void build() {
  for (int i = 1; i < N; i++) {
    phi[i] = i;
  }

  for (int i = 2; i < N; i++) {
    if (phi[i] == i) {
      for (int j = i; j < N; j+=i) {
        phi[j] -= phi[j]/i;
      }
    }
  }
}

vector<int> g[N];
int pai[N], lvl[N];

void dfs(int u) {
  for (int v : g[u]) {
    lvl[v] = lvl[u]+1;
    dfs(v);
  }
}

void buildTree() {
  for (int i = 2; i < N; i++) {
    pai[i] = phi[i];
    g[phi[i]].pb(i);
  }

  lvl[1] = 1;
  dfs(1);
}

struct Node {
  int lca;
  int ops;
  int size;

  Node() : lca(0), ops(0), size(0) {}

  Node(int l, int o, int s) : lca(l), ops(o), size(s) {}
};

Node lca(Node a, Node b) {
  int u = a.lca, v = b.lca;
  int ops = a.ops + b.ops;

  if (lvl[v] > lvl[u]) {
    swap(a, b);
    swap(u, v);
  }

  while(lvl[u] > lvl[v]) {
    u = pai[u];
    ops += a.size;
  }

  if (u == v) {
    return Node(u, ops, a.size + b.size);
  }

  while(u != v) {
    u = pai[u];
    v = pai[v];
    ops += a.size + b.size;
  }

  return Node(u, ops, a.size + b.size);
}

Node seg[4*M+1];
Node buildSeg(int r, int i, int j) {
  if (i == j) {
    return seg[r] = Node(a[i], 0, 1);
  }

  int mid = (i+j)>>1;
  Node L = buildSeg(2*r, i, mid);
  Node R = buildSeg(2*r+1, mid+1, j);

  seg[r] = lca(L, R);

  return seg[r];
}

int A, B;
Node query(int r, int i, int j) {
  if (j < A or i > B) {
    return Node(-1, -1, -1);
  }

  if (i >= A and j <= B) {
    return seg[r];
  }
  int mid = (i+j)>>1;
  Node L = query(2*r, i, mid);
  Node R = query(2*r+1, mid+1, j);

  if (L.lca == -1) return R;
  if (R.lca == -1) return L;

  return lca(L, R);
}

Node update(int r, int i, int j) {
  if (j < A or i > B) {
    return seg[r];
  }
  if (seg[r].lca == 1 and seg[r].ops == 0) {
    return seg[r];
  }

  if (i == j) {
    a[i] = phi[a[i]];
    seg[r].lca = a[i];
    return seg[r];
  }

  int mid = (i+j)>>1;
  Node L = update(2*r, i, mid);
  Node R = update(2*r+1, mid+1, j);

  return seg[r] = lca(L, R);
}

int main (void) {
  ios_base::sync_with_stdio(false);

  build();
  buildTree();

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  buildSeg(1, 0, n-1);

  while(m--) {
    int t;
    cin >> t >> A >> B;
    A--;  B--;

    if (t == 1) {
      update(1, 0, n-1);
    } else {
      cout << query(1, 0, n-1).ops << endl;
    }
  }

  return 0;
}
