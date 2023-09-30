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

ll s, d, k;

ll go() {

  cin >> s >> d >> k;

  if (!s && !d) {
    return !k;
  }

  ll x = min(s, d);

  ll t = x*3;

  s -= x;
  d -= x;

  t += s;

  if (!d) return t >= k;

  if (!t) {
    t = 1;
    d--;
  }

  t += d*2;

  return t >= k;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    cout << (go() ? "YES" : "NO") << endl;
  }

  return 0;
}

