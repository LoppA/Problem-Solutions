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

const int N = 1e5 + 5;
int n;
ll x[N];

double go() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  sort(x, x+n);

  if (n == 5) {
    double a1 = x[0]+x[2];      
    double b1 = x[3]+x[4];      

    double a2 = x[0]+x[1];      
    double b2 = x[2]+x[4]; 

    return max(b1-a1, b2-a2)/2.0;
  }

  double a = x[0]+x[1];
  double b = x[n-2]+x[n-1];
  return (b-a)/2.0;
}

int main (void) {
  int T;  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    printf("%.2lf\n", go());
  }

	return 0;
}

