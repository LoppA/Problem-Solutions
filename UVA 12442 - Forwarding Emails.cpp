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
const double E = exp(1);

const int N = 5e4 + 4;
int g[N], res[N], vis[N];
int mark, t;
int n;

void init (int at) {
	vis[at] = 1;

	res[at] = t++;

	int next = g[at];

	if (!vis[next])
		init(next);
	else if (vis[next] == 1) {
		mark = next;
		res[at] = res[at] - res[next] + 1;
	}

	if (next != mark) {
		if (mark) {
			res[at] = res[next];
		} else {
			res[at] = 0;
		}
	}

	if (mark == at)
		mark = 0;

	vis[at] = 2;
}

void go (int at) {
	int next = g[at];

	if (!res[next])
		go(next);
	
	res[at] = res[next] + 1;
}

int main (void) {
	ios_base::sync_with_stdio(false);

	int T;	cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		memset (vis, 0, sizeof vis);
		memset (res, 0, sizeof res);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;	cin >> a >> b;
			g[a] = b;
		}

		int ans = 0;

		cout << "Case " << tt << ": ";

		for (int i = 1; i <= n; i++) 
			if (!vis[i])
				init(i);

		for (int i = 1; i <= n; i++) {
			if (!res[i])
				go(i);
			ans = max(ans, res[i]);
		}

		for (int i = 1; i <= n; i++) {
			if (ans == res[i]) {
				cout << i << endl;
				break;
			}
		}
	}

	return 0;
}
