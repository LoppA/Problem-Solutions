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

vector<int> parse (const string &s, size_t &i) {
    auto isNumber = [] (const char c) -> bool {
        return '0' <= c && c <= '9';
    };
    auto parseInt = [&] (const string &s, size_t &i) -> int {
        int x = 0;
        while(i < s.size() && isNumber(s[i])) {
            x = x*10 + s[i++]-'0';
        }
        return x;
    };

    vector<int> v;
    while(i < s.size() && s[i] != ')') {
        if (isNumber(s[i])) {
            v.pb(parseInt(s, i));
        } else {
            i++;
        }
    }

    return v;
};

int mask;
vector<vector<int>> v;

// 2**12, 0 to 11
const int N = 4123;
const int M = 12;
int dp[N][M];

int go(int m, int i) {
    if (m == mask) {
        return 0;
    }
    if (i == (int)v.size()) {
        return 1000;
    }

    int &r = dp[m][i];
    if (r != INF) {
        return r;
    }

    r = go(m, i+1);

    for (auto j : v[i]) {
        m ^= (1<<j);
    }
    r = min(r, go(m, i+1) + 1);

    return r;
}

size_t mxI = 0;
int solve(string s) {
    mask = 0;
    size_t i = 1;
    v.clear();

    while(s[i] != ']') {
        if (s[i] == '#') {
            mask += (1<<(i-1));
        }
        i++;
    }
    i++;

    mxI = max(mxI, i);

    while(s[i] != '{') {
        if (s[i] == '(') {
            v.push_back(parse(s, i));
        }
        i++;
    }

    memset(dp, INF, sizeof dp);
    return go(0, 0);
}

int main (void) {
    ios_base::sync_with_stdio(false);

    string s;
    int ans = 0;
    while(getline(cin, s)) {
        ans += solve(s);
    }

    cout << ans << endl;

    return 0;
}

