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

const int N = 5e3+3;
ll freq[N];
ll dp[N];

ll go(int i) {
  if (i == 0) {
    return 0;
  }

  ll &r = dp[i];
  if (r != -1) {
    return r;
  }

  r = LLONG_MAX;

  for (int j = 0; j < i; j++) {
    r = min(r, (freq[j]-1)*i + j + go(j));
  }

  return r;
}

ll go() {
  memset(freq, 0, sizeof freq);
  memset(dp, -1, sizeof dp);
  int n;  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;  cin >> a;
    if (a > n) continue;
    freq[a]++;
  }

  for (int i = 0; i < n; i++) {
    debug(i, freq[i]);
  }

  for (int i = 0; i < n; i++) {
    if (!freq[i]) {
      return go(i);
    }
  }

  return 0;
}

int main (void) {
	ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  while(T--) {
    cout << go() << endl;
  }

	return 0;
}

