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

const int N = 51;
int n, m, k;
ll a[N], b[N];

ll go() {
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < m; i++)
    cin >> b[i];

  sort(a, a+n);
  sort(b, b+m);

  if (k == 1) {
    if (b[m-1] > a[0]) {
      swap(b[m-1], a[0]);
    }
    return accumulate(a, a+n, 0LL, plus<ll>());
  }

  if (k%2) {
    if (b[m-1] > a[0]) {
      swap(b[m-1], a[0]);
    }
    return accumulate(a, a+n, 0LL, plus<ll>());
  } 

  if (k%2 == 0) {
    if (b[m-1] > a[0]) {
      swap(b[m-1], a[0]);
      sort(a, a+n);
      sort(b, b+m);
    }
    for (int i = 0; i < n; i++) {
      debug(a[i]);
    }
    for (int i = 0; i < n; i++) {
      debug(b[i]);
    }
    if (a[n-1] > b[0]) {
      swap(b[0], a[n-1]);
    }
  }

 return accumulate(a, a+n, 0LL, plus<ll>());
}

int main (void) {
	ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  while(T--) {
    cout << go() << endl;
  }

	return 0;
}

