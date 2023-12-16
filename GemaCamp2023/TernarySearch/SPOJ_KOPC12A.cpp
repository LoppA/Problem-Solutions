// https://www.spoj.com/problems/KOPC12A/
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

const int N = 1e4 + 4;
int n, h[N], c[N];

ll f(int k) {
  ll cost = 0;

  for (int i = 0; i < n; i++) {
    cost += abs(h[i]-k)*c[i];
  }

  return cost;
}

ll ternary_search(int l, int r) {
  ll ans = LLONG_MIN;

  while(l <= r) {
    int len = (r-l)/3;
    int x1 = l + len;
    int x2 = r - len;

    ll c1 = f(x1), c2 = f(x2);

    if (c1 > c2) {
      ans = c2;
      l = x1+1;
    } else {
      ans = c1;
      r = x2-1;
    }
  }

  return ans;
}

int main (void) {
  ios_base::sync_with_stdio(false);


  int T;  cin >> T;
  while(T--) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> c[i];
    }

    cout << ternary_search(0, 10000) << endl;
  }
  

	return 0;
}


