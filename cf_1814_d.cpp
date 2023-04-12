// https://codeforces.com/contest/1814/problem/D
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<ll, ll> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 3e3 + 3, K = 1512, K2 = 2*K+100;
int n, k;
ll f[N], d[N];

vector<ii> ev[K2];
int freq[N];

ll l, r;
void add(int i, ll x, int y) {
  if (x < l or x > r) return;
  if (!x) return;
  ev[x-l].eb(i, y);
}

int go (ll dmg) {
  memset(freq, 0, sizeof freq);
  for (int i = 0; i < K2; i++) {
    ev[i].clear();
  }

  l = dmg - k, r = dmg + k;
  for (int i = 0; i < n; i++) {
    ll d1 = dmg/f[i];
    ll d2 = d1+1;

    add(i, d1*f[i], 0);
    add(i, d2*f[i], 0);
    add(i, d[i]*f[i], 1);
  }

  int ans = n;

  int cnt = 0, curr = 0;
  int j = 0;

  auto add = [&cnt, &curr](const int i) -> void {
    for (ii e : ev[i]) {
      if (freq[e.fi] == 0) {
        cnt++;
      }
      freq[e.fi]++;
      curr += e.se;
    }
  };
  auto rmv = [&cnt, &curr](const int i) -> void {
    for (ii e : ev[i]) {
      freq[e.fi]--;
      if (freq[e.fi] == 0) {
        cnt--;
      }
      curr -= e.se;
    }
  };

  while(j <= k) {
    add(j);
    j++;
  }

  for (int i = 0; i < K2; i++) {
    if (cnt == n) {
      ans = min(ans, n-curr);
    }

    rmv(i);

    if (j < K2) {
      add(j);
      j++;
    }
  }

  return ans;
}

int solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> f[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }

  int ans = n;
  for (int i = 0; i < n; i++) {
    ans = min(ans, go(f[i]*d[i]));
  }

  return ans;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  while(T--) {
    cout << solve() << endl;
  }

  return 0;
}
