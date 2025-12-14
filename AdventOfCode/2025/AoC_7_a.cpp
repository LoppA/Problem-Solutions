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

set<ii> vis;
vector<string> g;
int ans = 0;

void go(int i, int j) {
    if (i < 0 or i >= (int)g.size()) {
        return;
    }
    if (j < 0 or j >= (int)g[i].size()) {
        return;
    }

    if ( vis.count(ii(i,j)) ) {
        return;
    }
    vis.emplace(i, j);

    char c = g[i][j];

    if (c == '^') {
        ans++;
        go(i+1, j-1);
        go(i+1, j+1);
    } else {
        go(i+1, j);
    }

}

int solve() {
    for (size_t i = 0; i < g.size(); i++) {
        for (size_t j = 0; j < g[i].size(); j++) {
            if (g[i][j] == 'S') {
                go(i, j);
                return ans;
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

