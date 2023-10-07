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
typedef pair<ll, ll> ii;
typedef pair<ii, ii> pp;
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

const int N = 1e6 + 123;
const ll M = 1e9 + 6, MOD = 1e9 + 7;
int n;
ll v[N];

bool lazy[4*N+1];
pp seg[4*N+1];

pp merge(const pp &a, const pp &b) {
  return pp( max(a.fi, b.fi) , max(a.se, b.se) );
}

pp invert(const pp &a) {
  return pp(a.se, a.fi);
}

void build(int r, int i, int j) {
  lazy[r] = false;

  if (i == j) {
    seg[r] = pp( ii(v[i]%MOD, -(i+1)) , ii((v[i]*M)%MOD, -(i+1)) );
    return;
  }

  int mid = (i+j)/2;
  build(2*r, i, mid);
  build(2*r+1, mid+1, j);

  seg[r] = merge(seg[2*r], seg[2*r+1]);
}

void prop(int r, int i, int j) {
  if (!lazy[r]) return;

  seg[r] = invert(seg[r]);
  lazy[r] = false;

  if (i != j) {
    lazy[2*r] = !lazy[2*r];
    lazy[2*r + 1] = !lazy[2*r + 1];
  }
}

int a, b;
void update(int r, int i, int j) {
  prop(r, i, j);
  if (j < a or i > b) {
    return;
  }

  if (i >= a and j <= b) {
    lazy[r] = true;
    prop(r, i, j);
    return;
  }

  int mid = (i+j)/2;
  update(2*r, i, mid);
  update(2*r+1, mid+1, j);

  seg[r] = merge(seg[2*r], seg[2*r+1]);
}

ll go() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> v[i];

  build(1, 0, n-1);

  int q;  cin >> q;
  ll ans = 0;
  while(q--) {
    cin >> a >> b;
    a--;  b--;
    update(1, 0, n-1);

    ans -= seg[1].fi.se;
  }

  return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    cout << go() << endl;
  }

	return 0;
}

