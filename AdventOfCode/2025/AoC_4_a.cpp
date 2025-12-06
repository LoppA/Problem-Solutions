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

int main (void) {
    ios_base::sync_with_stdio(false);

    vector<string> g;
    string s;
    while(cin >> s) {
        g.pb(s);
    }

    int n = g.size();
    int m = g[0].size();

    auto check = [&](int i, int j) -> bool {
        if (g[i][j] != '@') {
            return false;
        }

        auto ins = [&n, &m](int i, int j) {
            return (0 <= i && i < n) &&
                   (0 <= j && j < m);
        };

        int cnt = 0;
        for (int a = -1; a <= 1; a++) {
            for (int b = -1; b <= 1; b++) {
                int x = i+a;
                int y = j+b;
                cnt += ins(x, y) && g[x][y] == '@';
            }
        }

        return cnt <= 4;

    };

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += check(i, j);
        }
    }

    cout << ans << endl;

    return 0;
}

