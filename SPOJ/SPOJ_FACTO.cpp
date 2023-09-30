// https://www.spoj.com/problems/FACT0/
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 5e7 + 7;
vector<ll> p;
bool vis[N];

void sieve() {
  for (int i = 2; i < N; i++) {
    if (!vis[i])  p.pb(i);
    for (int j = 0; j < p.size() and i*p[j] < N; j++) {
      vis[i*p[j]] = true;
      if (i%p[j]==0)  break;
    }
  }
}

void go(ll n) {
  bool f = false;

  for (ll x : p) {
    int y = 0;
    while(n%x == 0) {
      n /= x;
      y++;
    }

    if (y) {
      if (f)  cout << " ";
      cout << x << "^" << y;
      f = true;
    }
  }

  if (n > 1) {
    if (f)  cout << " ";
    cout << n << "^1";
  }

  cout << endl;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  sieve();

  ll n;
  while(cin >> n) {
    if (!n) return 0;
    go(n);
  }

  return 0;
}
