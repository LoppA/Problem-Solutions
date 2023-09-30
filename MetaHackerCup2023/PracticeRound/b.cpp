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

ll go() {
  int r, c, a, b;
  cin >> r >> c >> a >> b;

  return r > c;
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

