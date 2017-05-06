#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

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
// Dont work with negative coefs
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

const int N = 1e5 + 5;
vector <int> g[N];
int w[2*N], n, dist[N], sub[N], res[N];
bool cent[N];

int ctm;
vector <int> ct, ve;
int dfs (int at, int pai) {
	dist[at] = dist[pai] + 1;
	sub[at] = 1;
	ve.pb(at);

	if (ct.size()) {
		ct[dist[at]]++;
		ctm = max (dist[at], ctm);
	}

	for (int next : g[at]) {
		if (next == pai or cent[next])	continue;
		sub[at] += dfs (next, at);
	}

	return sub[at];
}

int find_centroid (int at, int pai, int total) {
	int mx = 0;

	for (int next : g[at]) {
		if (next == pai or cent[next])	continue;
		mx = max (sub[next], mx);
	}

	if (2*mx <= total)
		return at;

	for (int next : g[at]) {
		if (next == pai or cent[next])	continue;
		if (sub[next] == mx) 
			return find_centroid (next, at, total);
	}

	return 0;
}

int r[N];
void go (int at) {
	ct.clear();
	int total = dfs (at, 0);
	at = find_centroid (at, 0, total);
	if (!at)	return;
	cent[at] = 1;

	for (int next : g[at]) 
		if (!cent[next])
			go (next);

	ct.clear();	ct.resize (total);
	ctm = 0;
	dfs (at, 0);	reverse (ct.begin(), ct.end());
	vector <int> w;
	for (int i = 0; i <= 2*ctm; i++)
		w.pb(::w[i]);
	vector <int> a;	multiply (w, ct, a);
	for (int i = 0; i <= ctm; i++)
		r[i] = a[total - 1 + i];
	res[at] = r[0];

	for (int next : g[at]) {
		if (!cent[next]) {
			total = sub[next];
			ct.clear();	ct.resize (total + 1);
			ctm = 0;
			ve.clear();
			dfs (next, at);	reverse (ct.begin(), ct.end());
			vector <int> w;
			for (int i = 0; i <= 2*ctm; i++)
				w.pb(::w[i]);
			vector <int> a;	multiply (w, ct, a);
			for (int u : ve) {
				int d = dist[u];
				res[u] += r[d] - a[total + d];
			}
		}
	}

	cent[at] = 0;
}

int main (void) {

	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", w + i);
	for (int i = 1; i < n; i++) {
		int a, b;	scanf ("%d %d", &a, &b);
		g[a].pb(b);	g[b].pb(a);
	}

	dist[0] = -1;
	go (1);

	for (int i = 1; i <= n; i++)
		printf ("%d ", res[i]);
	printf ("\n");

	return 0;
}
