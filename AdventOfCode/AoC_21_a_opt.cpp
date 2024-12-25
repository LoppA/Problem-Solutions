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

const char BLANK = '#';

map<char, ii> dir = {
    {'v', ii(1,0)},
    {'^', ii(-1,0)},
    {'>', ii(0,1)},
    {'<', ii(0,-1)},
};

bool inside(int i, int j, int n, int m) {
    auto check = [](int i, int n) -> bool {
        return i >= 0 && i < n;
    };
    return check(i, n) && check(j, m);
}

namespace optimal_dir {

const int N = 2, M = 3;
const int C = N*M, L = 2;

vector<vector<char>> g = {
    {BLANK, '^', 'A'},
    {'<', 'v', '>'}
};
map<char, ii> pos;
map<char, int> id;

ll dp[C][C][L];

ll _go(ii a, ii b, int lvl, string &str);

ll go(char prev, char nxt, int lvl) {
    if (lvl == L) {
        return 1;
    }

    int i = id[prev];
    int j = id[nxt];
    ll &r = dp[i][j][lvl];
    if (r != -1) {
        return r;
    }

    string _;
    return r = _go(pos[prev], pos[nxt], lvl, _);
}

bool inside(int i, int j) {
    return ::inside(i, j, N, M) && g[i][j] != BLANK;
}

// Can memorize if needed, just O(4^3)
ll _go(ii a, ii b, int lvl, string &str) {
    if (a == b) {
        ll r = 0;
        char prev = 'A';
        for (char c : str) {
            r += go(prev, c, lvl+1);
            prev = c;
        }
        r += go(prev, 'A', lvl+1);
        return r;
    }
    if (str.size() >= 3) {
        return LLONG_MAX;
    }

    ll r = LLONG_MAX;

    for (const auto &it : dir) {
        char c = it.fi;
        ii d = it.se;

        ii aa = a;
        aa.fi += d.fi;
        aa.se += d.se;

        if (inside(aa.fi, aa.se)) {
            str += c;
            r = min(r, _go(aa, b, lvl, str));
            str.pop_back();
        }
    }

    return r;
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pos[g[i][j]] = ii(i, j);
            id[g[i][j]] = id.size();
        }
    }
}

ll solve(const string& s) {
    memset(dp, -1, sizeof dp);

    char prev = 'A';
    ll ans = 0;
    for (char c : s) {
        ans += go(prev, c, 0);
        prev = c;
    }
    return ans;
}

} // namespace optimal_dir

namespace optimal_num {

const int N = 4, M = 3;
const int C = N*M;

vector<vector<char>> g = {
    {'7', '8', '9'},
    {'4', '5', '6'},
    {'1', '2', '3'},
    {BLANK, '0', 'A'}
};
map<char, ii> pos;
map<char, int> id;

ll dp[C][C];

bool inside(int i, int j) {
    return ::inside(i, j, N, M) && g[i][j] != BLANK;
}

ll go(ii a, ii b, string &str) {
    if (a == b) {
        str += 'A';
        ll r =  optimal_dir::solve(str);
        // cout << str << " " << r << endl;
        str.pop_back();
        return r;
    }
    if (str.size() >= (N-1)+(M-1)) {
        return LLONG_MAX;
    }

    ll r = LLONG_MAX;

    for (const auto &it : dir) {
        char c = it.fi;
        ii d = it.se;

        ii aa = a;
        aa.fi += d.fi;
        aa.se += d.se;

        if (inside(aa.fi, aa.se)) {
            str += c;
            r = min(r, go(aa, b, str));
            str.pop_back();
        }
    }

    return r;
}

ll go(char prev, char nxt) {
    string _;
    return go(pos[prev], pos[nxt], _);
}

ll solve(const string& s) {
    memset(dp, -1, sizeof dp);

    char prev = 'A';
    ll ans = 0;
    for (char c : s) {
        // cout << endl << prev << "->" << c << endl;
        ans += go(prev, c);
        prev = c;
    }
    return ans;
}

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            pos[g[i][j]] = ii(i, j);
            id[g[i][j]] = id.size();
        }
    }
}

} // namespace optimal_num

ll solve() {
    auto parse = [] (const string &s) -> int {
        int val = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                val = val*10 + c-'0';
            }
        }
        return val;
    };

    string s;
    ll ans = 0;
    while(cin >> s) {
        // cout << optimal_dir::solve(s) << endl;
        ll r = optimal_num::solve(s);
        ll val = parse(s);
        cout << r << " " << val << endl;
        ans += r * val;
    }

    return ans;
}

int main (void) {
    ios_base::sync_with_stdio(false);

    optimal_dir::init();
    optimal_num::init();
    cout << solve() << endl;

    return 0;
}
