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

const int N = 5e5 + 5;
int vis[N], dv[N];
vector <int> a, res;

void crivo () {

	for (int i = 2; i < N; i++) 
		if (!vis[i])
			for (int j = i; j < N; j += i)
				vis[j] = i;
	
	a.pb(0);
	for (int i = 1; i < N; i++) {
		dv[i] = 1;
		int at = i, val = vis[at], ct = 0;
		while (at > 1) {
			val = vis[at];
			ct = 0;
			while (val == vis[at]) {
				ct++;
				at /= vis[at];
			}
			dv[i] *= (ct + 1);
		}
		a.pb(dv[i]);
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);

	crivo ();

	multiply (a, a, res);

	int n;
	while (cin >> n) {
		while (n--) {
			int a, b;	cin >> a >> b;
			int ans = a;
			for (int i = a; i <= b; i++)
				if (res[i] > res[ans])
					ans = i;
			cout << ans << " " << res[ans] << endl;
		}
	}

	return 0;
}
