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

const int N = 5e3 + 3;
int n, m;
vector<int> g[N];
double dp[N];
vector<double> p[N];

void build() {
  p[1] = {1.0};
  p[2] = {0.5, 0};

  for (int i = 3; i < N; i++) {
    p[i].pb(1.0/i);

    // Should be the same as 1/i;
    double x = p[i-2][0]*(i-2);
    p[i].pb(x/i);

    for (int j = 2; j < i; j++) {
      double x = p[i-2][j-2] * (j-1);
      x += p[i-2][j-1] * (i-1-j);

      p[i].pb(x/i);
    }
  }

  debug(p[1]);
  debug(p[2]);
  debug(p[3]);
  debug(p[4]);
  debug(p[5]);
  debug(p[6]);
}

double go() {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }

  scanf("%d %d", &n, &m);
  while(m--) {
    int u, v; scanf("%d %d", &u, &v);
    g[u].pb(v);
  }

  dp[n] = 1.0;
  for (int u = n-1; u > 0; u--) {
    if (g[u].empty()) {
      dp[u] = 0.0;
      continue;
    }

    vector<double> q;
    transform(g[u].begin(), g[u].end(), back_inserter(q),
      [] (int v) { return dp[v]; });
    sort(q.rbegin(), q.rend());

    int m = g[u].size();
    vector<double> v;
    transform(q.begin(), q.end(), p[m].begin(), back_inserter(v), multiplies<double>());
    dp[u] = accumulate(v.begin(), v.end(), 0.0, plus<double>());
  }

  return dp[1];
}

int main (void) {

  build();

  int T;  scanf("%d", &T);
  while(T--) {
    printf("%.9lf\n", go());
  }

	return 0;
}

