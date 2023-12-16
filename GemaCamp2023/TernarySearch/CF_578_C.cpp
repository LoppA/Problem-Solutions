// https://codeforces.com/problemset/problem/578/C
// g++ <fileName>.cpp -Wall -Wno-unused-value -DDEBUG
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
 
template <typename T>
std::ostream& operator<< (std::ostream& out, const vector<T>& v) {
    out << '[';
    bool f = false;
    for(auto& x:v){
      if (f)  out<<", ";
      f = true;
      out<<x;
    }
    out << "]";
    return out;
}
vector<string> vec_splitter(string s) {
  s += ',';
  vector<string> res;
  while(!s.empty()) {
    res.push_back(s.substr(0, s.find(',')));
    s = s.substr(s.find(',') + 1);
  }
  return res;
}
void debug_out(
  vector<string> __attribute__ ((unused)) args,
  __attribute__ ((unused)) int idx,
  __attribute__ ((unused)) int LINE_NUM) { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
  if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
  stringstream ss; ss << H;
  cerr << args[idx] << " = " << ss.str();
  debug_out(args, idx + 1, LINE_NUM, T...);
}
 
#ifdef DEBUG 
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define debug_endl() cout << endl;
#else
#define debug(...) 42
#define debug_endl(...) 42
#endif
 
const int N = 2e5 + 5;
int n, a[N];
 
double f(double x) {
  double res = 0;
  double at = 0;
 
  for (int i = 0; i < n; i++) {
    at += a[i] - x;
    if (at < 0) {
      at = 0;
    }
    res = max(res, abs(at));
  }
 
  at = 0;
  for (int i = 0; i < n; i++) {
    at += a[i] - x;
    if (at > 0) {
      at = 0;
    }
    res = max(res, abs(at));
  }
 
  return res;
}
 
double ternary_search(double l, double r) {
  int t = 1000;
 
  while(t--) {
    double len = (r-l)/3.0;
    double x1 = l + len;
    double x2 = x1 + len;
 
    if (f(x1) > f(x2)) {
      l = x1;
    } else {
      r = x2;
    }
  }
 
  return f(l);
}
 
int main (void) {
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+i);
  }
  printf("%.9lf\n", ternary_search(-1e9, 1e9));
 
  return 0;
}
 
