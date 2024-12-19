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

const int N = 70;
vector<string> v;

void read() {
    string line;
    getline(cin, line);

    stringstream s;
    s << line;

    while(s >> line) {
        assert(line.size());
        if (line.back() == ',') {
            line.pop_back();
        }
        v.push_back(line);
    }

    getline(cin, line); // consuime empty line
}

ll dp[N];

bool check(const string &s, const string &t, int i) {
    if (i + (int)t.size() > (int)s.size()) {
        return false;
    }

    for (int j = 0; j < (int)t.size(); j++) {
        if (t[j] != s[i+j]) {
            return false;
        }
    }

    return true;
}

ll go(const string &s, int i = 0) {
    if (i > (int)s.size()) {
        return 0;
    }
    if (i == (int)s.size()) {
        return 1;
    }

    ll &r = dp[i];
    if (r != -1) {
        return r;
    }

    r = 0;

    for (const string& t : v) {
        if (check(s, t, i)) {
            r += go(s, i+t.size());
        }
    }

    return r;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    ll ans = 0;
    string line;
    while(getline(cin, line)) {
        memset(dp, -1, sizeof dp);
        ans += go(line);
    }
    cout << ans << endl;

	return 0;
}
