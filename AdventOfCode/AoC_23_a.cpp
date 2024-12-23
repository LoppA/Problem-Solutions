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

map<string, set<string>> g;
set<string> nodes;

void read() {
    string line;

    auto add = [](const string& u, const string& v) {
        nodes.insert(u);
        if (u > v) {
            return;
        }
        if(!g.count(u)) {
            g[u] = set<string>();
        }
        g[u].insert(v);
    };

    while(cin >> line) {
        string u = line.substr(0, 2);
        string v = line.substr(3, 2);

        add(u, v);
        add(v, u);
    }
}

int go() {
    int ans = 0;

    auto hasT = [](vector<string> v) {
        for (const string &s : v) {
            if (s[0] == 't') {
                return true;
            }
        }
        return false;
    };

    for (const string &u : nodes) {
        for (auto j = g[u].begin(); j != g[u].end(); j++) {
            auto k = j;
            const string &v = *j;
            while(++k != g[u].end()) {
                const string &w = *k;
                if (!hasT({u, v, w})) {
                    continue;
                }
                if (!g.count(v) || !g[v].count(w)) {
                    continue;
                }
                ans++;
            }
        }
    }

    return ans;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    cout << go() << endl;

	return 0;
}
