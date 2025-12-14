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

map<ii, ll> dp;
vector<string> g;
int ans = 0;

ll go(int i, int j) {
    if (i < 0 or i >= (int)g.size()) {
        return 1;
    }
    if (j < 0 or j >= (int)g[i].size()) {
        return 1;
    }

    if ( dp.count(ii(i,j)) ) {
        return dp[ii(i,j)];
    }

    ll &r = dp[ii(i,j)];

    if (g[i][j] == '^') {
        ll L = go(i+1, j-1);
        ll R = go(i+1, j+1);
        return r = L+R;
    }
    
    return r = go(i+1, j);
}

ll solve() {
    for (size_t i = 0; i < g.size(); i++) {
        for (size_t j = 0; j < g[i].size(); j++) {
            if (g[i][j] == 'S') {
                return go(i, j);
            }
        }
    }
    assert(0);
    return 0;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;
    while(cin >> s) {
        g.pb(s);
    }

    cout << solve() << endl;

    return 0;
}

