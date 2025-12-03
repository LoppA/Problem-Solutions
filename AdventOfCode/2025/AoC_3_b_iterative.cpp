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

ll dp[15][111];

ll go() {
    memset(dp[0], 0, sizeof dp[0]);

    dp[1][0] = ctoi(s[0]);
    for (int j = 2; j <= 12; j++) {
        dp[j][0] = -10e13; 
    }

    for (int i = 1; i < (int)s.size(); i++) {
        for (int j = 1; j <= 12; j++) {
            dp[j][i] = max(dp[j][i-1], dp[j-1][i-1]*10 + ctoi(s[i]));
        }
    }

    return dp[12][s.size()-1];
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

