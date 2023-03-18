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

int m = 4;
int n = 2*m;
int v[100];
//int v[] = {3, 3, 3, 3, 3, 1};

int go(int i, int cnt, ll p, ll s) {
  if (cnt > n or i - cnt > n) {
    return -1;
  }
  if (i == n) {
    if (cnt != m) {
      return -1;
    }
    //cout << p << " " << s << endl;
    return p == s;
  }

  int L = go(i+1, cnt+1, p*v[i], s);
  int R = go(i+1, cnt, p, s+v[i]);

  if (L == -1 and R == -1) {
    return -1;
  }
  if (L == -1) {
    return R;
  }
  if (R == -1) {
    return L;
  }
  return L && R;
}

void check() {
  if (go(0, 0, 1, 0) == 1) {
    for (int i = 0; i < n; i++) {
      cout << v[i] << " ";
    }
    cout << endl;
  }
}

void go(int i) {
  if (i == n) {
    check();
    return;
  }

  for (int x = -m; x <= m; x++) {
    v[i] = x;
    go(i+1);
  }
}

int main (void) {
  ios_base::sync_with_stdio(false);

  go(0);

  return 0;
}

