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

map<string, vector<string>> g;
map<string, int> id;
map<int, string> rid;

const int N = 6000;
ll dp[N];

ll go (const string &curr) {
    if (curr == "out") {
        return 1;
    }

    ll &r = dp[id[curr]];
    if (r != -1) {
        return r;
    }
    r = 0;

    for (const string &nxt : g[curr]) {
        r += go(nxt);
    }

    return r;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string line;
    while(getline(cin, line)) {
        stringstream s(line);

        string u;
        s >> u;
        u.pop_back();
        g[u] = vector<string>();
        int i = id.size();
        id[u] = i;
        rid[i] = u;

        string v;
        while(s >> v) {
            g[u].push_back(v);
        }
    }

    memset(dp, -1, sizeof dp);
    cout << go("you") << endl;

    return 0;
}

