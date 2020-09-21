    /*https://codeforces.com/contest/528/problem/D*/
   
    #pragma GCC optimize("Ofast")
    #pragma GCC target("avx,avx2,fma")
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
     
    template<typename T>
    void mult(vector<T> &a, vector<T> &b, const int n, vector<T> &res) {
      if(n <= 64) {
        for(int i = 0; i < n; i++)
          for(int j = 0; j < n; j++)
            res[i+j] += a[i]*b[j];
        return;
      }
     
      int mid = n/2;
      vector<T> _a(mid), _b(mid);
      vector<T> E(n);
     
      mult<T>(a, b, mid, res);           // r0 = a0*b0, r0*x^0
     
      for(int i = 0; i < mid; i++) {  // a1, b1
        _a[i] = a[i+mid];
        _b[i] = b[i+mid];
      }
      mult<T>(_a, _b, mid, E);           // r2 = a1+b1
      for(int i = 0; i < n; i++)
        res[i+n] = E[i];              // *= x^n
     
      for(int i = 0; i < mid; i++) {  // (a0+a1), (b0+b1)
        _a[i] = a[i] + a[i+mid];
        _b[i] = b[i] + b[i+mid];
      }
      fill(E.begin(), E.end(), 0);
      mult<T>(_a, _b, mid, E);           // E = (a0+a1)*(b0+b1)
     
      for(int i = 0; i < mid; i++) {  // (E-r0-r2)*x^mid
        const T tmp = res[i+mid];
        res[i+mid]     += E[i]     - res[i] - res[i+n];
        res[i+mid+mid] += E[i+mid] - tmp    - res[i+n+mid];
      }
    }
     
    template<typename T>
    void mult(const vector<T> &a, const vector<T> &b, vector<T> &res) {
      int n = 1;
      while(n < (int)max(a.size(), b.size()))  n <<= 1;
      vector<T> _a(a.begin(), a.end());
      vector<T> _b(b.begin(), b.end());
      _a.resize(n, 0); _b.resize(n, 0);
     
      res.resize(2*n);
      fill(res.begin(), res.end(), 0);
      mult<T>(_a, _b, n, res);
    }
     
    const int N = 2e5 + 67;
    int n, m, k;
    string s, t;
    int cnt[N];
     
    int ev[N];
    void go(const char c) {
      vector<int> v(n, 0);
      memset(ev, 0, sizeof ev);
     
      for(int i = 0; i < n; i++) {
        if(s[i] == c) {
          ev[max(i-k, 0)]++;
          ev[min(i+k+1, N-1)]--;
        }
      }
     
      int at = 0;
      for(int i = 0; i < n; i++) {
        at += ev[i];
        v[i] = (at > 0);
      }
      reverse(v.begin(), v.end());
     
      vector<int> u(m, 0);
      for(int i = 0; i < m; i++) {
        u[i] = (t[i] == c);
      }
     
      mult<int>(v, u, v);
      v.resize(n);
      reverse(v.begin(), v.end());
      for(int i = 0; i < n; i++) {
        cnt[i] += v[i];
      }
    }
     
    int main (void) {
    	ios_base::sync_with_stdio(false);
     
      cin >> n >> m >> k;
      cin >> s >> t;
     
      go('A');
      go('T');
      go('G');
      go('C');
     
      int ans = 0;
      for(int i = 0; i < n; i++)
        ans += (cnt[i] == m);
      cout << ans << endl;
     
    	return 0;
    }
