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

int n;
vector<ll> a;

ll go(int i, int j, int k = -1) {
  ll target = a[i] + a[j];

  if (k != -1 && a[k] >= target) {
    return LLONG_MAX;
  }

  while(i < j) {
    if (a[i] + a[j] == target) {
      i++;
      j--;
    } else {
      if (k != -1) {
        return LLONG_MAX;
      }
      if (a[i] + a[j] > target) {
        k = j--;
      } else {
        k = i++;
      }
    }
  }

  // cout << i << " " << j << " " << k << " " << target << endl;

  if (i == j) {
    return target - a[i];
  }
  return target - a[k];
}


ll go() {
  cin >> n;
  a = vector<ll>(2*n-1);
  for (ll &x : a) {
    cin >> x;
  }

  if (n == 1) {
    return 1;
  }

  sort(a.begin(), a.end());

  // for (int x : a) cout << x << " "; cout << endl;

  ll ans = LLONG_MAX;

  ans = min(ans, go(1, a.size()-1, 0));
  ans = min(ans, go(0, a.size()-2, a.size()-1));
  ans = min(ans, go(0, a.size()-1));

  return ans == LLONG_MAX ? -1 : ans;
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

