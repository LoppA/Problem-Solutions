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

string s;

int ctoi(char c) {
    return c-'0';
}

ll dp[111][15];

ll go(int i, int n) {
    if (n == 0) {
        return 0;
    }
    if (i < 0) {
        return 0;
    }

    ll &r = dp[i][n];
    if (r != -1) {
        return r;
    }

    ll L = go(i-1, n);
    ll R = go(i-1, n-1)*10 + ctoi(s[i]);

    return r = max(L, R);
}

ll go() {
    memset(dp, -1, sizeof dp);
    return go(s.size()-1, 12);
}

int main (void) {
    ios_base::sync_with_stdio(false);

    ll ans = 0;
    while(cin >> s) {
        ans += go();
    }

    cout << ans << endl;

    return 0;
}

