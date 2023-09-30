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

ll a, b, c;

ll go() {
  cin >> a >> b >> c;

  ll d = c/b;
  ll a1 = d*2 - 1;

  if (a > c) {
    return max(a1, 0LL);
  }

  c -= a;
  ll a2 = 1;

  if (b <= a*2) {
    ll d = c/b;
    a2 += d*2;
    c %= b;
  } else {
    ll s = c/a;
    a2 += s;
    c %= a;
  }

  if (b <= c) {
    a2 += (c/b)*2;
  }

  if (a <= c) {
    a2 += (c/a);
  }

  return max(a1, a2);
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    cout << go() << endl;
  }

  return 0;
}

