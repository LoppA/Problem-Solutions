#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

bool go(vector<int> &v) {
	for (int i = 1; i < (int)v.size(); i++) {
		int d = v[i] - v[i-1];
		if (d > 3 || d < 1) {
			return false;
		}
	}
	return true;
}

bool check(vector<int> v) {
	if (go(v)) {
		return true;
	}
	reverse(v.begin(), v.end());
	return go(v);
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
