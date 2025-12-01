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

const int H = 450;
const int MAX = 100;
const char BLANK = '#';

map<char, ii> dir = {
    {'v', ii(1,0)},
    {'^', ii(-1,0)},
    {'>', ii(0,1)},
    {'<', ii(0,-1)},
};

bool inside(int i, int j, int n, int m) {
    auto check = [] (int i, int n) {
        return i >= 0 && i < n;
    };
    return check(i, n) && check(j, m);
}

class KeyPad {
public:
    int i, j;

    int N, M;
    vector<vector<char>> g;
    vector<vector<char>> vis;
    map<char, ii> pos;

    KeyPad(int N, int M, vector<vector<char>> G) : N(N), M(M), g(G) {
        vis = vector<vector<char>>(N, vector<char>(M, BLANK));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                pos[g[i][j]] = ii(i, j);
            }
        }
        this->i = pos['A'].fi;
        this->j = pos['A'].se;
    }

    bool inside(int i, int j) {
        return ::inside(i, j, N, M) && g[i][j] != BLANK;
    }

    char curr() {
        return g[i][j];
    }

    bool press(char c) {
        if (c == 'A') {
            return true;
        }

        int ii = i + dir[c].fi;
        int jj = j + dir[c].se;
        if (!inside(ii, jj)) {
            throw string("Invalid move");
        }
        this->i = ii;
        this->j = jj;
        return false;
    }

    int hash() const {
        return i*M + j;
    }

    int size() const {
        return N*M;
    }
};

class NumPad : public KeyPad {
public:
    const static int N = 4, M = 3;

    NumPad() : KeyPad(N, M, {
                {'7', '8', '9'},
                {'4', '5', '6'},
                {'1', '2', '3'},
                {BLANK, '0', 'A'}
            }) {}
};

class DirPad : public KeyPad {
public:
    const static int N = 2, M = 3;

    DirPad() : KeyPad(N, M, {
                {BLANK, '^', 'A'},
                {'<', 'v', '>'}
            }) {}
};

class State {
public:
    NumPad np;
    DirPad dp1, dp2;

    State() : np(), dp1(), dp2() {}

    char press(char c) {
        if (!dp2.press(c)) {
            return BLANK;
        }

        if (!dp1.press(dp2.curr())) {
            return BLANK;
        }

        if (np.press(dp1.curr())) {
            return np.curr();
        }

        return BLANK;
    }

    int hash() const {
        int r = np.hash();
        r = r*dp1.size() + dp1.hash();
        r = r*dp2.size() + dp2.hash();

        assert(r < H);
        return r;
    }
};

int dp[H][4][MAX];
string line;
int go(const State &at, int i, int len) {

    if (i == (int)line.size()) {
        return len; 
    }
    if (len >= MAX) {
        return INF;
    }

    int h = at.hash();
    assert(h >= 0 && h < H);
    int &r = dp[h][i][len];
    if (r != -1) {
        return r;
    }
    r = INF;
    State st = at;
    try {
        char c = st.press('A');
        r = go(st, i + (c == line[i]), len+1);
    } catch (const string &e) {
    }

    for (auto it : dir) {
        State st = at;
        try {
            st.press(it.fi);
            r = min(r, go(st, i, len+1));
        } catch (const string &e) {
        }
    }

    return r;
}

int go() {
    auto parse = [] (const string &s) -> int {
        int val = 0;
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                val = val*10 + c-'0';
            }
        }
        return val;
    };
    int val = parse(line);

    memset(dp, -1, sizeof dp);
    State at;
    int res = go(at, 0, 0);

    cout << res << " " << val << endl;
    return val * res;
}

int main (void) {
	ios_base::sync_with_stdio(false);

    int ans = 0;
    while(cin >> line) {
        ans += go();
    }
    cout << ans << endl;

	return 0;
}
