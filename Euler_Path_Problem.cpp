/*	https://csacademy.com/contest/round-48/task/matching-substrings

	Euler Path Problem 
*/

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

const int N = 2e5 + 5;
int n, k;
map <string, int> id;
string rid[N];
vector <int> g[N];
vector <char> p[N];
int in[N], out[N], edg_id[N];

string res;
void go (int at) {

	while (edg_id[at] < (int)g[at].size()) {
		int eid = edg_id[at]++;
		int next = g[at][eid];

		go (next);
		res += p[at][eid];
	}
}

int main (void) {
	ios_base::sync_with_stdio(false);
	
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string s;	cin >> s;
		string pre, suf;

		if (k > 1)
			pre += s[0];
		for (int i = 1; i < k - 1; i++) {
			pre += s[i];
			suf += s[i];
		}
		if (k > 1)
			suf += s[k-1];

		if (!id.count(pre))	id[pre] = id.size();
		if (!id.count(suf))	id[suf] = id.size();
		rid[id[pre]] = pre;
		rid[id[suf]] = suf;

		g[id[pre]].pb(id[suf]);
		p[id[pre]].pb(s[k-1]);
	}

	n = id.size();
	for (int at = 1; at <= n; at++) {
		out[at] = g[at].size();

		for (auto next : g[at])
			in[next]++;
	}

	int beg = -1;
	bool f = true;
	for (int at = 1; at <= n; at++) {
		if (out[at] > in[at]) {
			if (out[at] - in[at] > 1 or beg != -1) {
				f = false;
			}
			beg = at;
		}
	}

	if (!f) {
		cout << -1 << endl;
		return 0;
	}

	if (beg == -1)
		beg = 1;
	
	go (beg);
	string sbeg = rid[beg];
	reverse(sbeg.begin(), sbeg.end());
	res += sbeg;

	for (int at = 1; at <= n; at++) {
		if (edg_id[at] < (int)g[at].size()) {
			cout << -1 << endl;
			return 0;
		}
	}

	reverse(res.begin(), res.end());
	cout << res << endl;

	return 0;
}
