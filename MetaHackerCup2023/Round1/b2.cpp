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

vector<int> v;
vector<int> ans, tmp;
int aSum;

void go(int p, int sum) {
  if (sum > 41) {
    return;
  }
  if (ans.size() && ans.size() - aSum <= tmp.size()) {
    return;
  }

  if (p == 1) {
    if (ans.empty() || ans.size() - aSum > tmp.size() - sum) {
      ans = tmp;
      aSum = sum;
    }
    return;
  }

  for (auto x : v) {
    if (p%x == 0) {
      tmp.pb(x);
      go(p/x, sum+x);
      tmp.pop_back();
    }
  }
}

void go() {
  int n, p;
  cin >> n;
  p = n;

  v.clear();

  for (int x = 2; x <= 41; x++) {
    if(n%x == 0) {
      v.pb(x);
    }
  }

  int sum = 0;
  for (int x = 2; x <= 41; x++) {
    while(n%x == 0) {
      n /= x;
      sum += x;
    }
  }
  if (n != 1) {
    cout << -1 << endl;
    return;
  }
  if (sum > 41) {
    cout << -1 << endl;
    return;
  }

  ans.clear();  aSum = 0;
  go(p, 0);

  ans.insert(ans.end(), 41-aSum, 1);
  sort(ans.begin(), ans.end());
  cout << ans.size() << " ";
  for (int x : ans) cout << x << " ";
  cout << endl;
}

int main (void) {
  ios_base::sync_with_stdio(false);

  int T;  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    go();
  }

	return 0;
}

