// https://codeforces.com/problemset/problem/528/D
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

typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n=(int) a.size();
	for (int i=1, j=0; i<n; ++i) {
		int bit=n>>1;
		for (;j>=bit;bit>>=1)
			j-=bit;
		j+=bit;
		if(i<j)
			swap(a[i],a[j]);
	}
	for (int len=2; len<=n; len<<=1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i=0; i<n; i+=len) {
			base w(1);
			for (int j=0; j<len/2; ++j) {
				base u=a[i+j], v=a[i+j+len/2]*w;
				a[i+j]=u+v;
				a[i+j+len/2]=u-v;
				w*=wlen;
			}
		}
	}
	if (invert)
		for(int i=0;i<n;++i)
			a[i]/=n;
}

// a, b => coefs to multiply,  res => resulting coefs
// a[0], b[0], res[0] = coef x^0
// Doesnt work with negative coefs
void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
	vector<base> fa (a.begin(), a.end()),  fb (b.begin(), b.end());
	size_t n=1;
	while (n<max(a.size(),b.size())) n<<=1;
	n<<=1;
	fa.resize(n),fb.resize(n);
	fft (fa,false);  fft(fb,false);
	for (size_t i=0; i<n; ++i)
		fa[i]*=fb[i];
	fft (fa, true);
	res.resize (n);
	// avoid precision errors, mess up with negative values of coefs
	for(size_t i=0; i<n; ++i)
		res[i]=int(fa[i].real() + 0.5);
}

const int N = 2e5 + 5;
int n, m, k;
string s, t;

int mtch[4][N];

void match(char c, int id) {
  vector<int> ev(n+1, 0);
  for (int i = 0; i < n; i++) {
    if (s[i] != c)  continue;
    int l = max(0, i-k);
    int r = min(n-1, i+k);
    ev[l]++;
    ev[r+1]--;
  }

  vector<int> a(n, 0);
  int acc = 0;
  for (int i = 0; i < n; i++) {
    acc += ev[i];
    a[i] = (acc > 0);
  }

  vector<int> b(m, 0);
  int freq = 0;
  for (int i = 0; i < m; i++) {
    b[i] = (t[i] == c);
    freq += b[i];
  }
  reverse(b.begin(), b.end());

  vector<int> res;
  multiply(a, b, res);

  for (int i = 0; i < n; i++) {
    mtch[id][i] = (res[i] == freq);
  }
}

int main (void) {
	ios_base::sync_with_stdio(false);

  cin >> n >> m >> k;
  cin >> s >> t;

  match('A', 0);
  match('T', 1);
  match('G', 2);
  match('C', 3);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += (mtch[0][i] && mtch[1][i] && mtch[2][i] && mtch[3][i]);
  }

  cout << ans << endl;

  return 0;
}

