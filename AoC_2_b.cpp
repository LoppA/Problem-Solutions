#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int N = 20;
int dp[N][2];

bool go(vector<int> &v, int i = 1, bool f = false) {
	int n = v.size();
	if (i >= n) {
		return true;
	}

	int &r = dp[i][f];
	if (r != -1) {
		return r;
	}

	r = false;

	int d = v[i]-v[i-1];
	if (d >= 1 && d <= 3) {
		r |= go(v, i+1, f);
	}
	if (!f) {
		if (i+1 < n) {
			d = v[i+1] - v[i-1];
			if (d >= 1 && d <= 3) {
				r |= go(v, i+2, true);
			}
		} else {
			r = true;
		}
	}

	return r;
}

bool check(vector<int> v) {
	memset(dp, -1, sizeof dp);
	if (go(v) || go(v, 2, 1)) {
		return true;
	}
	memset(dp, -1, sizeof dp);
	reverse(v.begin(), v.end());
	return go(v) || go(v, 2, 1);
}

int main (void) {
	ios_base::sync_with_stdio(false);

	string line;
	int ans = 0;
	while(getline(cin, line)) {
		stringstream ss(line);

		int x;
		vector<int> v;
		while(ss >> x) {
			v.push_back(x);
		}
		ans += check(v);
	}

	cout << ans << endl;

	return 0;
}
