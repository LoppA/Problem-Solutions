// https://www.spoj.com/problems/FACT1/
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

LL gcd(LL a, LL b){
  if (b == 0) return a;
  else return gcd(b,a%b);
}

LL abs128(LL x) {
  if (x <= 0) return -x;
  return x;
}

LL convertLL(string s) {
  LL x = 0, f = 1;
  if (!s.size())  return x;
  int i = 0;
  char ch = s[i];
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    i++;
  }
  while (i < (int)s.size()) {
    x = x * 10 + s[i++] - '0';
  }
  return x * f;
}

string printLL(LL x) {
  string s;
  if (x < 0) {
    s += '-';
    x = -x;
  }
  if (x > 9) s += printLL(x / 10);
  s += (x % 10 + '0');
  return s;
}

LL mult(LL x, LL y, LL mod) {
  LL r = 0;
  x %= mod;
  y %= mod;

  while(y) {
    if (y&1)
      r = (x+r)%mod;
    x = (x+x)%mod;
    y >>= 1;
  }

  return r;
}

LL exp(LL x, ll y, LL mod) {
  LL r = 1;
  x %= mod;

  while(y) {
    if (y&1)
      r = mult(x, r, mod);
    x = mult(x, x, mod);
    y >>= 1;
  }

  return r;
}

// Fermat's little theorem: a^(n-1) = 1 % n
// n-1 = 2^s * d
// a^(n-1) = 1 mod n
// a^(2^s * d) - 1 = 0 mod n
// (a^(2^(s-1)d + 1)(a^(2^(s-2)d + 1)...(a^(2^d) + 1)(a^(2^d) - 1) = 0 mod n
// If none of these terms are equal 0 mod n, we are sure that n is not a prime.
// Otherwise n is **likely** a prime, need to try with other bases a.
// O(log3(n))
bool checkComposite(LL n, int a, LL d, int s) {
  LL x = exp(a, d, n);

  if (x == 1 or x == n-1)
    return false;

  for (int r = 1; r < s; r++) {
    x = mult(x, x, n);
    if (x == n-1)
      return false;
  }

  return true;
}

// Returns true if n is prime, else returns false.
// O(k*log3(n)), k = number of bases tested.
bool millerRabin(LL n) {
  if (n < 2)
    return false;

  // n-1 = (2^s)*d;
  int s = 0;
  LL d = n-1;
  while((d&1) == 0) {
    d >>= 1;
    s++;
  }

  // Checking all base a <= 2ln(n)^2 is enough
  // But for a 64 bit integer, the first 12 primes work.
  // For 32 bit integer the first 4 primes work {2, 3, 5, 7}.
  for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
    if (n == a)
      return true;
    if (checkComposite(n, a, d, s))
      return false;
  }
  return true;
}

// O( sqrt(sqrt(n)) )
LL rho(const LL n, const ll x0=2, const ll c=1) {
  if (n == 1) return 1;

  auto f = [&c, &n](LL x) {
    return (mult(x, x, n) + c)%n;
  };

  LL x = x0;
  LL g = 1;
  LL q = 1;
  LL xs, y;

  int m = 128;
  int l = 1;
  while(g == 1) {
    y = x;
    for (int i = 1; i < l; i++)
      x = f(x);

    int k = 0;
    while (k < l && g == 1) {
      xs = x;
      for (int i = 0; i < m && i < l-k; i++) {
        x = f(x);
        q = mult(q, abs128(y-x), n);
      }
      g = gcd(q, n);
      k += m;
    }

    l *= 2;
  }

  if (g == n) {
    do {
      xs = f(xs);
      g = gcd(abs128(xs - y), n);
    } while(g == 1);
  }

  return g;
}

class Factor {
private:
  vector<pair<LL, int>> v;
  LL n;

  void _factor(LL m) {
    while(m != 1 and millerRabin(m) == false) {
      LL d = m;
      for (int c = 1; d == m; c++) {
        d = rho(m, 2, c);
      }

      _factor(d);

      while(m%d == 0) {
        m /= d;
      }
    }

    if (m != 1) {
      int cnt = 0;
      while(n%m == 0) {
        n /= m;
        cnt++;
      }
      if (cnt) {
        v.emplace_back(m, cnt);
      }
    }
  }

public:
  Factor(LL n) : n(n) {}

  void factor() {
    _factor(n);

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
      cout << printLL(v[i].fi) << "^" << v[i].se << " \n"[i == v.size()-1];
    }
  }

};

void factor(LL n) {
  assert(n > 1);
}

int main (void) {
  ios_base::sync_with_stdio(false);

  string s;
  while (cin >> s, s != "0") {
    LL n = convertLL(s);
    Factor F = Factor(n);
    F.factor();
  }

  return 0;
}
