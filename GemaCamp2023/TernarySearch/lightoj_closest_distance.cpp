// https://lightoj.com/problem/closest-distance
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

pair<double, double> a, b, c, d;
pair<double, double> u, v;

pair<double, double> sub(pair<double, double> a, pair<double, double> b) {
  return {a.fi-b.fi, a.se-b.se};
}

pair<double, double> add(pair<double, double> a, pair<double, double> b) {
  return {a.fi+b.fi, a.se+b.se};
}

pair<double, double> mul(pair<double, double> a, double t) {
  return {a.fi*t, a.se*t};
}

double dist2(pair<double, double> a, pair<double, double> b) {
  double dx = a.fi-b.fi;
  double dy = a.se-b.se;

  return dx*dx + dy*dy;
}

double f(double t) {
  pair<double, double> p1 = add(a, mul(u, t));
  pair<double, double> p2 = add(c, mul(v, t));

  return dist2(p1, p2);
}

double ternary_search(double l, double r) {
  int t = 1000;

  while(t--) {
    double len = (r-l)/3.0;
    double x1 = l + len;
    double x2 = r - len;

    if (f(x1) > f(x2)) {
      l = x1;
    } else {
      r = x2;
    }
  }

  return sqrt(f(l));
}

int main (void) {

  int T;
  scanf("%d", &T);

  for (int tt = 1; tt <= T; tt++) {
    scanf("%lf %lf %lf %lf", &a.fi, &a.se, &b.fi, &b.se);
    scanf("%lf %lf %lf %lf", &c.fi, &c.se, &d.fi, &d.se);

    u = sub(b, a);
    v = sub(d, c);

    printf("Case %d: %.9lf\n", tt, ternary_search(0.0, 1.0));
  }

	return 0;
}

