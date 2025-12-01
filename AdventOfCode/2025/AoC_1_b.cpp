#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef __int128 LL;
typedef pair<int, int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int MOD = 100;

int main (void) {
	ios_base::sync_with_stdio(false);

    auto orbits = [](int n) -> int {
        if (n >= 0) {
            return n/MOD;
        }
        return ((n+1)/MOD) - 1;
    };

    ll curr = 50;
    int ans = 0;
    string s;
    while(cin >> s) {
        auto c = s.begin();
        int sig = ((*c == 'L') ? -1 : 1);
        int val = 0;
        while(++c != s.end()) {
            val *= 10;
            val += (*c - '0');
        }

        if (!val) {
            continue;
        }

        int pre = curr;
        curr += sig * val;

        ans += sig * (orbits(curr) - orbits(pre));

        if (sig == -1) {
            if (pre%MOD == 0) {
                ans--;
            }
            if (curr%MOD == 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;

	return 0;
}
