// https://codeforces.com/contest/1814/problem/E
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 2e9 + 9;
const double PI = acos(-1.0);

const int N = 2e5 + 5;
int n;
ll a[N];

struct Node {
  ll dp[2][2];

  Node() {
    memset(dp, 0, sizeof dp);
  }

  Node(int i) {
    dp[0][0] = INF;
    dp[0][1] = a[i];
    dp[1][0] = 0;
    dp[1][1] = a[i];
  }
} seg[4*N+1];

void merge(int r, int i, int j) {
  auto &dp = seg[r].dp;
  auto &L = seg[2*r].dp, &R = seg[2*r+1].dp;

  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 2; b++) {
      dp[a][b] = min(L[a][1] + R[1][b], L[a][0] + R[0][b]);
    }
  }
}

int L, R;
void update(int r, int i, int j) {
  if (j < L or i > R) return;

  if (i == j) {
    seg[r] = Node(i);
  } else {
    int mid = (i+j)/2;
    update(2*r, i, mid);
    update(2*r+1, mid+1, j);
    merge(r, i, j);
  }
}

ll query() {
  return seg[1].dp[0][1] * 2LL;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  cin >> n; n--;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  L = 0,  R = n-1;
  update(1, 0, n-1);

  int q;  cin >> q;
  while(q--) {
    ll k, x;  cin >> k >> x;
    k--;
    a[k] = x;

    L = R = k;
    update(1, 0, n-1);
    cout << query() << endl;
  }

  return 0;
}
