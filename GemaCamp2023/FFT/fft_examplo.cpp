#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef complex<double> base;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<base> fft (const vector<base> &a, bool invert) {
  const int n = a.size();
  assert(n >= 1);
  if (n == 1) {
    return a;
  }
  base wn = invert ?
    exp(base(0.0, -2.0*PI/n)):
    exp(base(0.0, 2.0*PI/n)); // e^(2*PI*i/n)
  base w = 1;

  vector<base> a_even, a_odd;
  for (int i = 0; i < n; i+=2) {
    a_even.pb(a[i]);
    a_odd.pb(a[i+1]);
  }

  vector<base> y_even = fft(a_even, invert);
  vector<base> y_odd = fft(a_odd, invert);

  vector<base> y(n);
  for (int i = 0; i < n/2; i++) {
    base u = y_even[i], v = w * y_odd[i];
    y[i] = u+v;
    y[i+n/2] = u-v;
    w *= wn;
  }

  return y;
}

vector<int> mult(vector<int> a, vector<int> b) {
  int n = 1;
  while(n < (int)max(a.size(), b.size()))  n <<= 1;
  n<<=1;
  vector<base> _a(a.begin(), a.end()), _b(b.begin(), b.end());
  _a.resize(n, 0); _b.resize(n, 0);

  vector<base> y_a = fft(_a, false);
  vector<base> y_b = fft(_b, false);

  vector<base> y(n);
  for (int i = 0; i < n; i++) {
    y[i] = y_a[i] * y_b[i];
  }

  vector<base> res = fft(y, true);

  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    res[i] /= n;
    c[i] = nearbyint(res[i].real());
  }

  return c;
}


int main (void) {
  ios_base::sync_with_stdio(false);

  vector<int> a = {1, 1, 1};
  vector<int> b = {-3, 0, 1};
  vector<int> c = mult(a, b);

  for (auto coef : c) {
    cout << coef << " ";
  }
  cout << endl;

  return 0;
}

