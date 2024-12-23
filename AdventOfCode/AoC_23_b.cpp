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
vector<string> nodes;

void read() {
    string line;

    auto add = [](const string& u, const string& v) -> void {
        nodes.push_back(u);
        if (u < v) {
            return;
        }
        if(!g.count(u)) {
            g[u] = vector<string>();
        }
        g[u].push_back(v);
    };

    while(cin >> line) {
        string u = line.substr(0, 2);
        string v = line.substr(3, 2);

        add(u, v);
        add(v, u);
    }

    auto dedup = [](vector<string> &v) -> void {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    };

    dedup(nodes);
    for (auto &it : g) {
        dedup(it.se);
    }
}

vector<string> curr;

inline bool check(const string &u) {
    const vector<string> &v = g[u];
    int n = v.size();
    int i = 0;

    for (const string &w : curr) {
        while (i < n && v[i] != w) {
            i++;
        }
        if (i == n) {
            return false;
        }
    }

    return true;
}

int go(int i = 0, int target = -1) {
    assert((int)curr.size() <= 83); // Max possible
    if (i >= (int)nodes.size()) {
        if ((int)curr.size() == target) {
            for (int j = 0; j < (int)curr.size(); j++) {
                cout << curr[j] << (j == (int)curr.size()-1 ? '\n' : ',');
            }
        }
        return curr.size();
    }

    int r = 0;
    if (check(nodes[i])) {
        curr.push_back(nodes[i]);
        r = go(i+1, target);
        curr.pop_back();
    }

    return max(go(i+1, target), r);
}

int main (void) {
	ios_base::sync_with_stdio(false);

    read();
    go(0, go());

	return 0;
}
