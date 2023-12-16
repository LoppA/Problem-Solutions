// https://www.spoj.com/problems/MUL/
// Implementacao mais facil de entender, sacrificando otimizacoes por legibilidade
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
    c[i] = int(res[i].real() + 0.5);
  }

  return c;
}

inline vector<int> strToVec(const string &s) {
  vector<int> v(s.size());
  for(int i = 0; i < (int)s.size(); i++) {
    v[i] = (s[i] - '0');
  }
  reverse(v.begin(), v.end());
  return v;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  while(T--) {
    string s, t;
    cin >> s >> t;
    vector<int> v = strToVec(s);
    vector<int> u = strToVec(t);
    vector<int> ans = mult(v, u);

    int carry = 0;
    int j = 0;
    for(int i = 0; i < (int)ans.size(); i++) {
      ans[i] += carry;
      carry = ans[i]/10;
      ans[i] %= 10;

      if(ans[i]) j = i;
    }

    while(j >= 0) {
      cout << ans[j];
      j--;
    }
    cout << endl;
  }

  return 0;
}

