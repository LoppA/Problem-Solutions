#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

vector<string> g;
int n, m;
map<char, ii> dir = {
    {'<', ii(0, -1)},
    {'>', ii(0, 1)},
    {'^', ii(-1, 0)},
    {'v', ii(1, 0)},
};

ll fin () {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j];
            ans += g[i][j] == '[' ? i*100 + j : 0;
        }
        cout << endl;
    }
    return ans;
}

vector<string> prep(const vector<string> &g) {
    vector<string> res;
    for (const string &s : g) {
        string t;
        for (const char c : s) {
            if (c == 'O') {
                t += "[]";
            } else if (c == '@') {
                t += "@.";
            } else {
                t += c;
                t += c;
            }
        }
        res.push_back(t);
    }

    return res;
}

ii find_robot() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '@') {
                return ii(i, j);
            }
        }
    }
    assert(0);
    return ii(0,0);
}

bool inside(const ii &pos) {
    return pos.fi >= 0 && pos.se >= 0 && pos.fi < n && pos.se < m;
}

bool check(const ii &dir, const ii &pos) {
    if (!inside(pos)) {
        return false;
    }
    int i = pos.fi, j = pos.se;
    if (g[i][j] == '#') {
        return false;
    }
    if (g[i][j] == '.') {
        return true;
    }

    int _i = i+dir.fi;
    int _j = j+dir.se;
    if (dir.fi) {
        if (g[i][j] == '[') {
            return check(dir, ii(_i, _j)) && check(dir, ii(_i, _j+1));
        } else if (g[i][j] == ']') {
            return check(dir, ii(_i, _j)) && check(dir, ii(_i, _j-1));
        }
    }

    return check(dir, ii(_i, _j));
}

void go(const ii &dir, const ii &pos) {
    assert(inside(pos));
    int i = pos.fi, j = pos.se;
    assert(g[i][j] != '#');

    if (g[i][j] == '.') {
        return;
    }

    int _i = i+dir.fi;
    int _j = j+dir.se;
    if (dir.fi) {
        if (g[i][j] == '[') {
            go(dir, ii(_i, _j));
            go(dir, ii(_i, _j+1));
            swap(g[i][j], g[_i][_j]);
            swap(g[i][j+1], g[_i][_j+1]);
            return;
        } else if (g[i][j] == ']') {
            go(dir, ii(_i, _j));
            go(dir, ii(_i, _j-1));
            swap(g[i][j], g[_i][_j]);
            swap(g[i][j-1], g[_i][_j-1]);
            return;
        }
    }


    go(dir, ii(_i, _j));
    swap(g[i][j], g[_i][_j]);
}

void process(const string &s) {
    ii pos = find_robot();

    for (char c : s) {
        if (check(dir[c], pos)) {
            go(dir[c], pos);
            pos.fi += dir[c].fi;
            pos.se += dir[c].se;
        }
    }
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string line;
    while(getline(cin, line) && !line.empty()) {
        g.push_back(line);
    }
    g = prep(g);
    n = g.size();
    m = g[0].size();

    while(getline(cin, line)) {
        process(line);
    }
    cout << fin() << endl;

    return 0;
}
